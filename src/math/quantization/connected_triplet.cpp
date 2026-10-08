#include "connected_triplet.hpp"
#ifndef CONNECT727_ENTRY
#define CONNECT727_ENTRY prepare_connected_triplet727
#endif
#ifndef CONNECT727_MUTANT
#define CONNECT727_MUTANT 0
#endif
namespace hum::reconstruction::reach {
namespace {
struct PrivateView final : native_bitstream_writer_memory {
    native_bitstream_writer_memory& guest; const triplet556& local; std::uint64_t token;
    PrivateView(native_bitstream_writer_memory& g,const triplet556& l,std::uint64_t t):guest(g),local(l),token(t){}
    std::uint32_t read32(std::uint64_t a) override {
        if(a==token)return local[0];
        if(a==token+4)return local[1];
        if(a==token+8)return local[2];
        return guest.read32(a);
    }
    std::uint16_t read16(std::uint64_t a) override {return guest.read16(a);}
    std::uint64_t read64(std::uint64_t a) override {return guest.read64(a);}
    void write8(std::uint64_t a,std::uint8_t v) override {guest.write8(a,v);}
    void write32(std::uint64_t a,std::uint32_t v) override {guest.write32(a,v);}
    void write64(std::uint64_t a,std::uint64_t v) override {guest.write64(a,v);}
};
struct Connected final : dependencies556 {
    native_bitstream_writer_memory& guest; transport727& transport; std::uint64_t token,constant;
    Connected(native_bitstream_writer_memory& g,transport727& t,std::uint64_t l,std::uint64_t k):guest(g),transport(t),token(l),constant(k){}
    comparison556 call93634(triplet556& local,std::uint64_t target,carriers556 c) override {
        PrivateView view(guest,local,token);
        registers570 r{0,token,target,c.r8,c.r9,c.r10,c.r11};
#if CONNECT727_MUTANT == 2
        r.rcx=c.r11;
#endif
        const auto result=compare_triplet570(view,r,constant);
        const auto& n=result.gpr;
        carriers556 next{n.rdx,n.r8,n.r9,n.r10,n.r11};
#if CONNECT727_MUTANT == 1
        ++next.r9;
#endif
        return {static_cast<std::uint8_t>(n.rax),next};
    }
    carriers556 call1de64(std::uint64_t x,std::uint64_t y,triplet556& l,carriers556 c) override {return transport.call1de64(x,y,l,c);}
    void call3c9a68(std::uint32_t x,std::uint64_t y,std::uint64_t z,std::uint64_t w) override {transport.call3c9a68(x,y,z,w);}
};
}
void CONNECT727_ENTRY(native_bitstream_writer_memory& m,transport727& t,const inputs556& in,std::uint64_t k) {
    Connected d(m,t,in.local_address,k);
    prepare_quantized_triplet556(m,d,in);
}
}
