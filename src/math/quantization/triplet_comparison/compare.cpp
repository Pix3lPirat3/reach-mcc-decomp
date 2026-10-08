#include "compare.hpp"
#include <bit>
#include <immintrin.h>
#ifndef COMPARE570_ENTRY
#define COMPARE570_ENTRY compare_triplet570
#endif
#ifndef COMPARE570_MUTANT
#define COMPARE570_MUTANT 0
#endif
namespace hum::reconstruction::reach {
namespace {
float scalar(std::uint32_t x){return std::bit_cast<float>(x);}
float sub(float x,float y){return _mm_cvtss_f32(_mm_sub_ss(_mm_set_ss(x),_mm_set_ss(y)));}
}
comparison570 COMPARE570_ENTRY(native_bitstream_writer_memory& m,registers570 r,std::uint64_t constant_address) {
    float x0=scalar(m.read32(r.rcx));
    const float x1=0.0f;
    float x3=scalar(m.read32(r.rdx+4));
    float x4=scalar(m.read32(r.rcx+4));
    x3=sub(x3,x0);
    x0=sub(x0,scalar(m.read32(r.rdx)));
    float x5=scalar(m.read32(r.rdx+12));
    x4=sub(x4,scalar(m.read32(r.rdx+8)));
    x5=sub(x5,scalar(m.read32(r.rcx+4)));
    float x2=scalar(m.read32(constant_address));
    float x6=scalar(m.read32(r.rcx+8));
    x6=sub(x6,scalar(m.read32(r.rdx+16)));
    float x7=scalar(m.read32(r.rdx+20));
    x7=sub(x7,scalar(m.read32(r.rcx+8)));

    const std::array<float,6> tests{x0,x3,x4,x5,x6,x7};
    for(unsigned i=0;i<tests.size();++i) {
#if COMPARE570_MUTANT == 1
        if(i==4) continue;
#endif
#if COMPARE570_MUTANT == 2
        if(tests[i]<x1) x2=0.0f;
#else
        if(!(tests[i]>=x1)) x2=0.0f;
#endif
    }

    const float constant_again=scalar(m.read32(constant_address));
    const bool al=x2==constant_again;
    r.rax=(r.rax&~std::uint64_t{255})|static_cast<std::uint64_t>(al);
    return {r,{std::bit_cast<std::uint32_t>(x0),0,std::bit_cast<std::uint32_t>(x2),
        std::bit_cast<std::uint32_t>(x3),std::bit_cast<std::uint32_t>(x4),std::bit_cast<std::uint32_t>(x5)}};
}
}
