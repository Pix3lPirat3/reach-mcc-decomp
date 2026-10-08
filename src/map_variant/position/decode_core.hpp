#pragma once
#include "decode.hpp"
namespace hum::reconstruction::reach::recon1550 {
namespace position_shared_detail {
inline address sx32(std::uint32_t x) { return (x & 0x80000000U) ? (0xffffffff00000000ULL | x) : x; }
inline lanes dword(std::uint32_t x) { return {x,0,0,0}; }
inline lanes qword(std::uint64_t x) { return {static_cast<std::uint32_t>(x),static_cast<std::uint32_t>(x>>32),0,0}; }
inline std::uint64_t low64(const lanes& x) { return x[0] | (static_cast<std::uint64_t>(x[1])<<32); }
inline bool signed_ge(std::uint32_t a,std::uint32_t b) { return (a ^ 0x80000000U) >= (b ^ 0x80000000U); }
template<class Dependencies,class State>
void interpolate(Dependencies& d,State& r,address frame,address bounds,address encoded,address output,bool candidate) {
    r.rdx=0; r.r8=bounds;
    do {
        if (candidate) { r.rcx=d.read32(frame+r.rdx-0x50); r.rax=1; }
        r.xmm[2]=dword(d.read32(r.r8+4));
        if (!candidate) r.rax=1;
        r.xmm[2][0]=d.sse32(scalar_sse::sub,r.xmm[2][0],d.read32(r.r8));
        if (!candidate) r.rcx=d.read32(frame+r.rdx-0x50);
        r.xmm[1]=dword(d.read32(encoded+r.rdx));
        const std::uint32_t shifted=std::uint32_t{1} << (r.rcx & 31); r.rax=static_cast<std::uint64_t>(shifted);
        r.xmm[1]=d.cvtdq2ps(r.xmm[1]);
        r.xmm[0]=dword(static_cast<std::uint32_t>(r.rax));
        r.xmm[0]=d.cvtdq2ps(r.xmm[0]);
        r.xmm[2][0]=d.sse32(scalar_sse::div,r.xmm[2][0],r.xmm[0][0]);
        r.xmm[1][0]=d.sse32(scalar_sse::mul,r.xmm[1][0],r.xmm[2][0]);
        r.xmm[2][0]=d.sse32(scalar_sse::mul,r.xmm[2][0],r.xmm[5][0]);
        r.xmm[1][0]=d.sse32(scalar_sse::add,r.xmm[1][0],d.read32(r.r8));
        r.r8+=8;
        r.xmm[1][0]=d.sse32(scalar_sse::add,r.xmm[1][0],r.xmm[2][0]);
        d.write32(output+r.rdx,r.xmm[1][0]);
        r.rdx+=4;
    } while (r.rdx<12);
}
template<class Dependencies,class State>
State decode_core(Dependencies& d,address module,address frame,State r) {
    r.rax=d.read64(module+0xafa010); r.rax^=frame-0x70;
    d.write64(frame-0x10,r.rax);
    const auto supplied_bounds=d.read64(frame+0x68);
    const auto table=module+0xbfeb90;
    const auto width=sx32(static_cast<std::uint32_t>(r.r8));
    auto bounds=supplied_bounds ? supplied_bounds : table;
    d.write32(frame-0x50,static_cast<std::uint32_t>(width));
    d.write32(frame-0x4c,static_cast<std::uint32_t>(width));
    const auto repair_flag=static_cast<std::uint8_t>(r.r9);
    d.write32(frame-0x48,static_cast<std::uint32_t>(width));
    const auto position=r.rdx, reader=r.rcx;
    r=d.call_54214(r);
    bool transform=false;
    if (static_cast<std::uint8_t>(r.rax)!=0) {
        if (!supplied_bounds) {
            r.rcx=width+width*2;
            r.xmm[0]=qword(d.read64(table+r.rcx*4+0x34));
            r.rax=d.read32(table+r.rcx*4+0x3c);
            d.write64(frame-0x50,low64(r.xmm[0]));
            d.write32(frame-0x48,static_cast<std::uint32_t>(r.rax));
        } else transform=true;
    } else if (supplied_bounds) transform=true;
    else {
        r.rcx=reader; r=d.call_54214(r);
        if (static_cast<std::uint8_t>(r.rax)!=0) bounds=module+0xbfebac;
        else {
            r.rdx=2; r.rcx=reader; r=d.call_dd10c(r);
            if (static_cast<std::uint32_t>(r.rax)==0xffffffffU) bounds=module+0xbfebac;
            else {
                r.rax=sx32(static_cast<std::uint32_t>(r.rax));
                bounds=table+0x1b4;
                r.rcx=r.rax+r.rax*2;
                bounds+=r.rcx*8; transform=true;
            }
        }
    }
    if (transform) {
        r.r9=frame-0x50; r.rdx=bounds; r.rcx=static_cast<std::uint32_t>(width);
        r=d.call_3c9a68(r);
    }
    for (address offset=0;offset<12;offset+=4) {
        r.rdx=d.read32(frame+offset-0x50); r.rcx=reader;
        r=d.call_dd10c(r); d.write32(frame+offset-0x40,static_cast<std::uint32_t>(r.rax));
    }
    r.xmm[5]=dword(d.read32(module+0xa8ad74));
    interpolate(d,r,frame,bounds,frame-0x40,position,false);
    if (repair_flag && d.read8(frame+0x60)==0) {
        r.rcx=position; r=d.call_3c9a0c(r);
        if (static_cast<std::uint8_t>(r.rax)==0) {
            std::uint32_t iteration=0;
            auto delta=module+0xb71060-(frame-0x40);
            for (;;) {
                r.r8=0; r.rdx=0; bool invalid=false;
                do {
                    r.rax=frame-0x40; r.rax+=r.rdx;
                    r.r9=d.read32(r.rax+delta);
                    r.rax=d.read32(r.rax);
                    r.r9=static_cast<std::uint32_t>(r.r9)+static_cast<std::uint32_t>(r.rax);
                    r.r9=static_cast<std::uint32_t>(r.r9);
                    d.write32(frame+r.rdx-0x20,static_cast<std::uint32_t>(r.r9));
                    if (r.r9 & 0x80000000U) { invalid=true; break; }
                    r.rcx=d.read32(frame+r.rdx-0x50); r.rax=1;
                    const std::uint32_t shifted=std::uint32_t{1} << (r.rcx & 31); r.rax=static_cast<std::uint64_t>(shifted);
                    if (signed_ge(static_cast<std::uint32_t>(r.r9),static_cast<std::uint32_t>(r.rax))) { invalid=true; break; }
                    r.r8=static_cast<std::uint32_t>(r.r8)+1U; r.rdx+=4;
                } while (r.r8<3);
                if (!invalid) {
                    interpolate(d,r,frame,bounds,frame-0x20,frame-0x30,true);
                    r.rcx=frame-0x30; r=d.call_3c9a0c(r);
                    if (static_cast<std::uint8_t>(r.rax)!=0) {
                        r.xmm[0]=qword(d.read64(frame-0x30)); r.rax=d.read32(frame-0x28);
                        d.write64(position,low64(r.xmm[0])); d.write32(position+8,static_cast<std::uint32_t>(r.rax));
                        break;
                    }
                }
                ++iteration; delta+=12;
                if (iteration>=14) break;
            }
        }
    }
    r.rcx=d.read64(frame-0x10); r.rcx^=frame-0x70;
    return d.call_787e00(r);
}
}
}
