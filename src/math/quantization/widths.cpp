#include "widths.hpp"
#include <array>
#include <bit>
#include <immintrin.h>

extern "C" unsigned int hum_reach_range_bit_width(unsigned int);
#ifndef WIDTHS624_ENTRY
#define WIDTHS624_ENTRY quantized_widths624
#endif
#ifndef WIDTHS624_MUTANT
#define WIDTHS624_MUTANT 0
#endif
namespace hum::reconstruction::reach {
namespace {
float value(std::uint32_t b) { return std::bit_cast<float>(b); }
float subtract(float a,float b) {
    return _mm_cvtss_f32(_mm_sub_ss(_mm_set_ss(a),_mm_set_ss(b)));
}
float divide(float a,float b) {
    return _mm_cvtss_f32(_mm_div_ss(_mm_set_ss(a),_mm_set_ss(b)));
}
}
result624 WIDTHS624_ENTRY(memory624& m,dependencies624& d,const inputs624& in) {
    const auto saved_cookie=m.read64(in.module+0xafa010U);

    const auto upper0=value(m.read32(in.bounds+4));
    const auto lower0=value(m.read32(in.bounds));
    const auto difference0=subtract(upper0,lower0);
    const auto upper1=value(m.read32(in.bounds+12));
    const auto lower1=value(m.read32(in.bounds+8));
    const auto difference1=subtract(upper1,lower1);
    const auto upper2=value(m.read32(in.bounds+20));
    const auto lower2=value(m.read32(in.bounds+16));
    const std::array<float,3> differences{difference0,difference1,subtract(upper2,lower2)};
    m.write32(in.output,in.raw_width);
    m.write32(in.output+4,in.raw_width);
    m.write32(in.output+8,in.raw_width);
    float scale;
#if WIDTHS624_MUTANT == 1
    const bool high=in.raw_width>16U;
#else
    const bool high=std::bit_cast<std::int32_t>(in.raw_width)>16;
#endif
    if(high) {
        const auto constant=value(m.read32(in.scale_constant));
        const auto shifted=std::uint32_t{1}<<((in.raw_width-16U)&31U);
        scale=divide(constant,static_cast<float>(std::bit_cast<std::int32_t>(shifted)));
    } else {
        const auto shifted=std::uint32_t{1}<<((16U-in.raw_width)&31U);
        scale=_mm_cvtss_f32(_mm_mul_ss(
            _mm_set_ss(static_cast<float>(std::bit_cast<std::int32_t>(shifted))),
            _mm_set_ss(value(m.read32(in.scale_constant)))));
    }
    const auto threshold=value(m.read32(in.threshold_constant));
#if WIDTHS624_MUTANT == 2
    const bool fallback=scale<threshold;
#else

    const bool fallback=!(scale>=threshold);
#endif
    std::uint64_t rax;
    if(fallback) {
        rax=0x1a0000001aULL;
        m.write64(in.output,rax);
        m.write32(in.output+8,26U);
    } else {
        scale=_mm_cvtss_f32(_mm_add_ss(_mm_set_ss(scale),_mm_set_ss(scale)));
        rax=0;
        for(unsigned axis=0;axis<3;++axis) {
            const auto divided=divide(differences[axis],scale);
            const auto returned=d.call91a13e(std::bit_cast<std::uint32_t>(divided));
            auto count=_mm_cvttss_si32(_mm_set_ss(value(returned)));
            if(count>0x800000) count=0x800000;
            rax=hum_reach_range_bit_width(std::bit_cast<std::uint32_t>(count));
            const auto width=rax<26U?static_cast<std::uint32_t>(rax):26U;
            m.write32(in.output+axis*4U,width);
        }
    }
    const auto checked=check_security_cookie_787e00(m,in.module,
        {rax,saved_cookie,0,0,0,0,0});
    return {checked.registers.rax,checked.disposition,checked.tail_target};
}
}
