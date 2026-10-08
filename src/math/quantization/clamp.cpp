#include "clamp.hpp"
#include <array>
#include <bit>
#include <limits>
#ifndef RECON639_ENTRY
#define RECON639_ENTRY triplet_clamp639
#endif
#ifndef RECON639_MUTANT
#define RECON639_MUTANT 0
#endif
namespace hum::recon639 {
static_assert(sizeof(float)==4 && std::numeric_limits<float>::is_iec559);
Registers RECON639_ENTRY(Memory& m,Registers r) {
    r.rdx-=r.r8;
    r.rax=3;
#if RECON639_MUTANT == 2
    std::array<std::uint32_t,6> cached{};
    for(unsigned i=0;i<6;++i)cached[i]=m.read32(r.rcx+4*i);
#endif
    do {
#if RECON639_MUTANT == 2
        auto selected=cached[2*(3-r.rax)];
#else
        auto selected=m.read32(r.rcx);
#endif
        const auto input=m.read32(r.rdx+r.r8);
#if RECON639_MUTANT == 1
        const bool lower_wins=std::bit_cast<float>(selected)<std::bit_cast<float>(input);
#else
        const bool lower_wins=std::bit_cast<float>(selected)>std::bit_cast<float>(input);
#endif
        if(!lower_wins) {
#if RECON639_MUTANT == 2
            selected=cached[2*(3-r.rax)+1];
#else
            selected=m.read32(r.rcx+4);
#endif
            if(!(std::bit_cast<float>(input)>std::bit_cast<float>(selected)))selected=input;
        }
#if RECON639_MUTANT == 3
        m.write32(r.r8,selected^0x80000000U);
#else
        m.write32(r.r8,selected);
#endif
        r.rcx+=8;r.r8+=4;--r.rax;
    }while(r.rax!=0);
    return r;
}
}
