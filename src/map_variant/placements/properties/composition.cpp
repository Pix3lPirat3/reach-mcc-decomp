#include "composition.hpp"
#include "../../../bitstream/quantized_scalar.hpp"
#include <bit>
#include <limits>
#include <stdexcept>

#ifndef PROPERTIES_ENTRY
#define PROPERTIES_ENTRY encode
#endif
#ifndef PROPERTIES_MUTANT
#define PROPERTIES_MUTANT 0
#endif
namespace hum::reconstruction::reach::properties_composition {
namespace ps = hum::reconstruction::reach::placement_scalars;
namespace q = hum::reconstruction::reach::recon671;
namespace {
bool valid(range r) { return r.size && r.begin <= std::numeric_limits<address>::max()-r.size; }
bool overlaps(range a, range b) { return a.begin < b.begin+b.size && b.begin < a.begin+a.size; }
bool contains(range r, address a, address n) { return a >= r.begin && n <= r.size && a-r.begin <= r.size-n; }
class guarded final : public memory {
    memory& base;
    admission allowed;
    address source;
    void check(address a, address n) const {
        for (const auto r : allowed.guest) if (contains(r,a,n)) return;
        throw std::runtime_error("outside_admitted_guest");
    }
public:
    guarded(memory& m, admission a, address src) : base(m), allowed(a), source(src) {
        const range frame{a.private_rsp,0x48};
        if (!valid(frame) || a.guest.empty()) throw std::runtime_error("invalid_private_frame");
        for (const auto r : a.guest) {
            if (!valid(r) || overlaps(r,frame)) throw std::runtime_error("private_frame_alias_or_wrap");
        }
    }
    std::uint8_t read8(address a) override { check(a,1); return base.read8(a); }
    std::uint16_t read16(address a) override { check(a,2); return base.read16(a); }
    std::uint32_t read32(address a) override {
#if PROPERTIES_MUTANT == 2
        if (a==source+4) a=source+8;
        else if (a==source+8) a=source+4;
#endif
        check(a,4); return base.read32(a);
    }
    std::uint64_t read64(address a) override { check(a,8); return base.read64(a); }
    std::array<std::uint8_t,16> read128(address a) override {
        check(a,16); auto result=base.read128(a);
#if PROPERTIES_MUTANT == 3
        result.fill(0xff);
#endif
        return result;
    }
    void write8(address a,std::uint8_t v) override { check(a,1); base.write8(a,v); }
    void write32(address a,std::uint32_t v) override { check(a,4); base.write32(a,v); }
    void write64(address a,std::uint64_t v) override { check(a,8); base.write64(a,v); }
};
class frame_view final : public q::Memory {
    memory& shared;
    ps::boundary call;
    address rsp;
    bool frame(address a,address n) const {
        if (a>std::numeric_limits<address>::max()-n) throw std::runtime_error("access_wrap");
        return overlaps({rsp,0x48},{a,n});
    }
    address slot(address offset) const {
#if PROPERTIES_MUTANT == 1
        return rsp+offset-8;
#else
        return rsp+offset;
#endif
    }
public:
    frame_view(memory& m,ps::boundary b,address s) : shared(m),call(b),rsp(s) {}
    std::uint8_t read8(address a) override {
        if (a==slot(0x38)) return call.stack30_low;
        if (a==slot(0x40)) return call.stack38_low;
        if (frame(a,1)) throw std::runtime_error("unprovided_private_read8");
        return shared.read8(a);
    }
    std::uint16_t read16(address a) override {
        if (frame(a,2)) throw std::runtime_error("unprovided_private_read16");
        return shared.read16(a);
    }
    std::uint32_t read32(address a) override {
        if (a==slot(0x28)) return call.stack20_low;
        if (a==slot(0x30)) return call.stack28;
        if (frame(a,4)) throw std::runtime_error("unprovided_private_read32");
        return shared.read32(a);
    }
    std::uint64_t read64(address a) override {
        if (frame(a,8)) throw std::runtime_error("unprovided_private_read64");
        return shared.read64(a);
    }
    void write8(address a,std::uint8_t v) override {
        if (frame(a,1)) throw std::runtime_error("unexpected_private_write");
        shared.write8(a,v);
    }
    void write32(address a,std::uint32_t v) override {
        if (frame(a,4)) throw std::runtime_error("unexpected_private_write");
        shared.write32(a,v);
    }
    void write64(address a,std::uint64_t v) override {
        if (frame(a,8)) throw std::runtime_error("unexpected_private_write");
        shared.write64(a,v);
    }
};
class provider final : public ps::imports {
    address private_rsp;
public:
    explicit provider(address s) : private_rsp(s) {}
    ps::continuation dc234(memory& m,const ps::boundary& b,ps::continuation opaque) override {
        if (b.xmm3_low!=0 || b.stack20_low!=b.xmm1_low || b.stack28!=11 ||
            b.stack30_low!=0 || b.stack38_low!=1) throw std::runtime_error("unexpected_scalar_boundary");
        frame_view view(m,b,private_rsp);
        (void)q::body_dc234(view,{b.stream,private_rsp,
            std::bit_cast<float>(b.xmm2_low),std::bit_cast<float>(b.xmm3_low)});

        return opaque;
    }
    std::uint64_t writer_effect(ps::continuation opaque,
        hum::reconstruction::reach::native_bitstream_writer_continuation) override { return opaque.token; }
};
}
void PROPERTIES_ENTRY(memory& m,address module,address source,address stream,admission a) {
    if (module>std::numeric_limits<address>::max()-0xa8ce70 ||
        source>std::numeric_limits<address>::max()-17 ||
        stream>std::numeric_limits<address>::max()-64) throw std::runtime_error("entry_address_wrap");
    guarded checked(m,a,source);
    provider actual(a.private_rsp);

    (void)ps::record(checked,actual,module,source,stream,{0,0},0);
}
}
