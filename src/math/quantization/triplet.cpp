#include "triplet.hpp"
#include <bit>
#include <immintrin.h>
#ifndef TRIPLET556_ENTRY
#define TRIPLET556_ENTRY prepare_quantized_triplet556
#endif
#ifndef TRIPLET556_MUTANT
#define TRIPLET556_MUTANT 0
#endif
namespace hum::reconstruction::reach {
namespace {
float scalar(std::uint32_t bits) { return std::bit_cast<float>(bits); }
float sub(float x,float y) { return _mm_cvtss_f32(_mm_sub_ss(_mm_set_ss(x),_mm_set_ss(y))); }
float div(float x,float y) { return _mm_cvtss_f32(_mm_div_ss(_mm_set_ss(x),_mm_set_ss(y))); }
std::uint64_t sx(std::uint32_t x) { return static_cast<std::uint64_t>(static_cast<std::int64_t>(std::bit_cast<std::int32_t>(x))); }
}
void TRIPLET556_ENTRY(native_bitstream_writer_memory& m,dependencies556& d,const inputs556& in) {
    const auto low = m.read64(in.source);
    const auto high = m.read32(in.source+8);
    triplet556 local{static_cast<std::uint32_t>(low),static_cast<std::uint32_t>(low>>32),high};
    auto selected = in.table;
    carriers556 c{selected,in.optional,in.flag,sx(in.raw_width),in.source};
    m.write32(in.widths,in.raw_width);
    m.write32(in.widths+4,in.raw_width);
    m.write32(in.widths+8,in.raw_width);
    m.write32(in.index,m.read32(in.index)|0xffffffffU);
    if(c.r8) selected=c.r8;
    c.rdx=selected;
    auto cmp=d.call93634(local,selected,c); c=cmp.next;
    m.write8(c.r9,cmp.al);
    if(cmp.al) {
        if(!c.r8) {
            const auto address=in.table+12*c.r10+0x34;
            const auto pair=m.read64(address); m.write64(in.widths,pair);
            const auto last=m.read32(address+8); m.write32(in.widths+8,last);
        } else d.call3c9a68(static_cast<std::uint32_t>(c.r10),c.rdx,c.r8,in.widths);
    } else if(c.r8) {
        c.r8=in.local_address; c.rdx=c.r11;
        c=d.call1de64(selected,c.r11,local,c);
        m.write8(c.r9,1);
        d.call3c9a68(static_cast<std::uint32_t>(c.r10),selected,c.r8,in.widths);
    } else {
        const auto mask=m.read32(in.mask_address);
        c.r9=0xffffffffU; c.r8=0;
        for(;;) {
            if((mask>>(c.r8&31U))&1U) {
                const auto address=in.table+0x1b4+24*sx(static_cast<std::uint32_t>(c.r8));
                c.rdx=address;
                cmp=d.call93634(local,address,c); c=cmp.next;
                if(cmp.al) { c.r9=static_cast<std::uint32_t>(c.r8); break; }
            }
            c.r8=static_cast<std::uint32_t>(c.r8+1);
            if(std::bit_cast<std::int32_t>(static_cast<std::uint32_t>(c.r8))>=16) break;
        }
        m.write32(in.index,static_cast<std::uint32_t>(c.r9));
        if(static_cast<std::uint32_t>(c.r9)==0xffffffffU) {
            selected=in.fallback;
            c.r8=in.local_address; c.rdx=c.r11;
            c=d.call1de64(selected,c.r11,local,c);
        } else {
            selected=in.table+0x1b4+24*sx(static_cast<std::uint32_t>(c.r9));
            d.call3c9a68(static_cast<std::uint32_t>(c.r10),selected,c.r8,in.widths);
        }
    }
    for(unsigned i=0;i<3;++i) {
        float value=scalar(local[i]);
        const auto width=m.read32(in.widths+4*i);
        const float minimum=scalar(m.read32(selected));
        const float delta=sub(value,minimum);
        const float maximum=scalar(m.read32(selected+4));
        const auto power=std::uint32_t{1}<<(width&31U);
        if(!(delta>=0.0f)) value=scalar(m.read32(selected));
        if(sub(value,maximum)>=0.0f) value=maximum;
        const float span=sub(maximum,scalar(m.read32(selected)));
        const float offset=sub(value,scalar(m.read32(selected)));
#if TRIPLET556_MUTANT == 1
        const auto divisor=static_cast<float>(power);
#else
        const auto divisor=_mm_cvtss_f32(_mm_cvtepi32_ps(_mm_set1_epi32(std::bit_cast<std::int32_t>(power))));
#endif
        auto q=_mm_cvttss_si32(_mm_set_ss(div(offset,div(span,divisor))));
        if(q<=0) q=0;
        auto result=power-1;
        if(q<=std::bit_cast<std::int32_t>(result)) result=static_cast<std::uint32_t>(q);
        selected+=8;
        m.write32(in.output+4*i,result);
    }
}
}
