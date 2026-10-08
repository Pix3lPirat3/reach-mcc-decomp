#include "populated.hpp"
#include "../../bitstream/optional_code_writer.hpp"
#include "../../math/quantization/composed_triplet.hpp"
#include "../../math/quantization/connected_triplet.hpp"
#include "../../math/scalar/ceilf_adapter.hpp"
#include <immintrin.h>
#include <limits>
#include <stdexcept>

namespace hum::reconstruction::reach::position_composition03 {
namespace {
void check_domain(const admission& a, std::uint32_t width) {
    if(width<1 || width>26 || (_mm_getcsr()&0xffc0U)!=0x1f80U)
        throw std::domain_error("position03 width or MXCSR excluded");
    constexpr auto maximum=std::numeric_limits<address>::max();
    if(a.classifier_private_token>maximum-12 || a.initialized_guest_extents.empty())
        throw std::domain_error("position03 private token or guest domain excluded");
    for(const auto& e:a.initialized_guest_extents) {
        if(e.size==0 || e.begin>maximum-e.size)
            throw std::domain_error("position03 invalid guest extent");
        if(a.classifier_private_token<e.begin+e.size && e.begin<a.classifier_private_token+12)
            throw std::domain_error("position03 classifier private token aliases guest RAM");
    }
}
struct WidthMemory final : memory624 {
    memory& ram;
    explicit WidthMemory(memory& m):ram(m){}
    std::uint16_t read16(address a) override{return ram.read16(a);}
    std::uint32_t read32(address a) override{return ram.read32(a);}
    address read64(address a) override{return ram.read64(a);}
    void write8(address a,std::uint8_t v) override{ram.write8(a,v);}
    void write32(address a,std::uint32_t v) override{ram.write32(a,v);}
    void write64(address a,address v) override{ram.write64(a,v);}
};
struct Children final : transport727 {
    memory& ram;const admission& admitted;
    Children(memory& m,const admission& a):ram(m),admitted(a){}
    carriers556 call1de64(address bounds,address input,triplet556& local,carriers556 c) override {
        return hum::recon724::clamp_local724(ram,local,admitted.classifier_private_token,bounds,input,c);
    }
    void call3c9a68(std::uint32_t width,address bounds,address unused_r8,address output) override {
        (void)unused_r8;
#ifdef POSITION03_SHIFT_WIDTH_OUTPUT
        output+=4;
#endif
        WidthMemory m(ram);recon1008::FiniteCeilfAdapter imported_ceil;
        const auto result=quantized_widths624(m,imported_ceil,
            {width,bounds,output,admitted.module+0xa8aa74,admitted.module+0xa8a9b8,admitted.module});
        if(result.cookie!=security_cookie_disposition::normal_return)
            throw std::domain_error("position03 widths cookie tail refused");
    }
};
struct Outer final : identifier_codec410::dependencies {
    memory& ram;const admission& admitted;
    Outer(memory& m,const admission& a):ram(m),admitted(a){}
    std::uint8_t read8(address a) override{return ram.read8(a);}
    std::uint16_t read16(address a) override{return ram.read16(a);}
    std::uint32_t read32(address a) override{return ram.read32(a);}
    address read64(address a) override{return ram.read64(a);}
    void write8(address a,std::uint8_t v) override{ram.write8(a,v);}
    void write32(address a,std::uint32_t v) override{ram.write32(a,v);}
    void write64(address a,address v) override{ram.write64(a,v);}
    void classify_3c6494(const identifier_codec410::classify_call& c) override {
        Children children(ram,admitted);
        const inputs556 input{c.rcx,c.r8,c.r9,c.fifth,c.sixth,c.seventh,c.edx,
            admitted.module+0xbfeb90,admitted.module+0x4e2fb2c,
            admitted.module+0xbfebac,admitted.classifier_private_token};

        prepare_connected_triplet727(ram,children,input,admitted.module+0xa8af18);
    }
    void scalar_f635c(const identifier_codec410::scalar_call& c) override {
#ifdef POSITION03_SKIP_SCALAR
        (void)c;
#else
        (void)write_optional_code523(ram,c.rcx,c.r8d);
#endif
    }
};
}
identifier_codec410::encode_result encode(memory& m,const admission& a,
    address stream,address point,std::uint32_t width,address bounds,
    identifier_codec410::workspace frame) {
    check_domain(a,width);
    Outer outer(m,a);
    return identifier_codec410::encode_continuation(outer,a.module,stream,point,width,bounds,frame);
}
}
