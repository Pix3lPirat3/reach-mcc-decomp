#include "compact.hpp"
#include "../lookups/lookup_6cf60.hpp"
#include "../lookups/lookup_6cfd0.hpp"
namespace hum::reach::transfer21 {
namespace {
U sx16(U value) {const auto x=value&65535U;return x&32768U?x|0xffffffffffff0000ULL:x;}
std::int32_t signed16(U value) {const auto x=static_cast<std::uint32_t>(value)&65535U;return x<32768U?static_cast<std::int32_t>(x):static_cast<std::int32_t>(x)-65536;}
void al(U& r,U value){r=(r&~U{255})|(value&255U);}
struct Metadata final : recon453::Memory,recon453::Dependency {
    hum::reach::transfer21::Memory& m;U module;PrivateInputs frames;
    Metadata(hum::reach::transfer21::Memory& ram,U base,PrivateInputs f):m(ram),module(base),frames(f){}
    U read(U a,unsigned n) override{return m.read(a,n);}
    void write(U a,unsigned n,U value) override{m.write(a,n,value);}
    recon453::Continuation call_6cfd0(recon453::Memory& ram,const recon453::Call6cfd0& c) override {
        const auto result=recon515::body_6cfd0(ram,module,
            {c.r8-0x38,frames.resolver_rbx,frames.resolver_rdi,c.rcx,c.rdx,c.r8,c.r9});
        return {result.r10,result.r11};
    }
};
}
Result compact_records(Memory& m,U module,U dst,U src,bool match,Registers r,PrivateInputs frames) {
    Metadata metadata(m,module,frames);
    U accepted=0;
    r.r8=0xffffffffU;
    for(U i=0;i<651;++i) {
        const U source=src+0x14fc+76*i;
        al(r.rax,m.read(source,1)&1U);
        if((r.rax&255U)==0)continue;
        r.rax=m.read(source+2,2);
        if(signed16(r.rax)<0)continue;
        if(signed16(r.rax)>=signed16(m.read(dst+0x2b2,2)))continue;
        if((r.r8&65535U)!=m.read(source+0x2c,2))continue;
        const U record=dst+0x14fc+76*accepted++;

        for(U offset=0;offset<64;offset+=16) {
            const auto bytes=m.read128(source+offset);m.write128(record+offset,bytes);
        }
        m.write(record+64,8,m.read(source+64,8));
        r.rax=m.read(source+72,4);m.write(record+72,4,r.rax);
        r.rcx=sx16(m.read(record+2,2));r.rax=dst+2*r.rcx;
#ifndef TRANSFER21_OMIT_QUOTA_INCREMENT
        const U quota=r.rcx+r.rax+0xd642;
        m.write(quota,1,static_cast<std::uint8_t>(m.read(quota,1)+1));
#endif
        if((r.r8&65535U)!=m.read(source+0x44,2)) {
            r.rcx=src+0x2f4;r.rax=sx16(m.read(source+0x44,2));
            r.rdx=sx16(m.read(r.rcx+2*r.rax+0x1004,2));
            if(static_cast<std::uint32_t>(r.rdx)!=static_cast<std::uint32_t>(r.r8)) {
                r.rdx+=r.rcx;
                if(r.rdx!=0) {
                    r.rcx=dst;
                    r=recon1552::append_6bb70(m,r,frames.remap_entry_rsp);
                    m.write(record+0x44,2,r.rax&65535U);r.r8=0xffffffffU;
                }
            }
        }
#ifndef TRANSFER21_OMIT_FIELD4_RESET
        m.write(record+4,4,static_cast<std::uint32_t>(r.r8));
#endif
        if(match) {
            const auto category=static_cast<std::uint32_t>(signed16(m.read(record+2,2)));
            r.rdx=category;
            const auto out=recon453::body_6cf60(metadata,metadata,module,
                {frames.metadata_entry_rsp,r.rcx,r.rdx,r.r10,r.r11});
            r={out.rax,out.rcx,out.rdx,out.r8,out.r9,out.r10,out.r11};
            r.rcx=m.read(r.rax+4,1);r.rax=m.read(record+0x2e,1);
            if(r.rax==0)r.rax=0;
#ifndef TRANSFER21_OMIT_TYPE_CLAMP
            if(static_cast<std::uint8_t>(r.rax)<=static_cast<std::uint8_t>(r.rcx))r.rcx=r.rax;
            m.write(record+0x2e,1,r.rcx&255U);
#endif
            r.r8=0xffffffffU;
        }
    }
    return {r,accepted,76*accepted};
}
}
