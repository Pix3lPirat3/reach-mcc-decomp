#include "composed_triplet.hpp"
#include <stdexcept>
#ifndef RECON724_ENTRY
#define RECON724_ENTRY prepare724
#endif
#ifndef RECON724_MUTANT
#define RECON724_MUTANT 0
#endif
namespace hum::recon724 {
namespace {
struct LocalMemory final : hum::recon639::Memory {
    native_bitstream_writer_memory& ram;triplet556& local;std::uint64_t token;
    LocalMemory(native_bitstream_writer_memory& m,triplet556& l,std::uint64_t t):ram(m),local(l),token(t){}
    bool private_word(std::uint64_t a) const {return a>=token && a-token<12;}
    std::uint32_t read32(std::uint64_t a) override {
        if(!private_word(a))return ram.read32(a);
        if((a-token)%4)throw std::invalid_argument("unaligned private access");
        return local[(a-token)/4];
    }
    void write32(std::uint64_t a,std::uint32_t v) override {
        if(!private_word(a)){ram.write32(a,v);return;}
        if((a-token)%4)throw std::invalid_argument("unaligned private access");
        local[(a-token)/4]=v;
    }
};
}
carriers556 clamp_local724(native_bitstream_writer_memory& ram,triplet556& local,
    std::uint64_t token,std::uint64_t bounds,std::uint64_t input,carriers556 c) {
    LocalMemory memory(ram,local,token);
    hum::recon639::Registers r{};
    r.rcx=bounds;r.rdx=input;r.r8=c.r8;r.r9=c.r9;r.r10=c.r10;r.r11=c.r11;
    r=hum::recon639::triplet_clamp639(memory,r);
    return {r.rdx,r.r8,r.r9,r.r10,r.r11};
}
void RECON724_ENTRY(native_bitstream_writer_memory& m,Transport& t,const inputs556& in) {
    struct Adapter final : dependencies556 {
        native_bitstream_writer_memory& ram;Transport& transport;std::uint64_t token;
        Adapter(native_bitstream_writer_memory& r,Transport& t,std::uint64_t l):ram(r),transport(t),token(l){}
        comparison556 call93634(triplet556& l,std::uint64_t a,carriers556 c) override{return transport.call93634(l,a,c);}
        carriers556 call1de64(std::uint64_t b,std::uint64_t input,triplet556& l,carriers556 c) override {
#if RECON724_MUTANT == 1
            auto result=clamp_local724(ram,l,token,b,input,c);result.r8=c.r8;return result;
#elif RECON724_MUTANT == 2
            auto result=clamp_local724(ram,l,token,b,input,c);l[0]^=0x80000000U;return result;
#else
            return clamp_local724(ram,l,token,b,input,c);
#endif
        }
        void call3c9a68(std::uint32_t w,std::uint64_t b,std::uint64_t r8,std::uint64_t out) override{transport.call3c9a68(w,b,r8,out);}
    } adapter(m,t,in.local_address);
    prepare_quantized_triplet556(m,adapter,in);
}
}
