#include "dependencies.hpp"
#include <cstdint>

namespace recon1552 {
namespace {
U low32(U value) {return static_cast<std::uint32_t>(value);}
U sign32(U value) {
    const auto bits=static_cast<std::uint32_t>(value);
    const auto extended=bits>0x7fffffffu?static_cast<std::int64_t>(bits)-0x100000000ll:static_cast<std::int64_t>(bits);
    return static_cast<U>(extended);
}
void set_al(U& value,U byte) {value=(value&~U{255})|(byte&255u);}
}

Registers append_6bb70(StringDependencies& d,Registers r,U native_entry_rsp) {

    r.rax=native_entry_rsp;
    const U base=r.rcx+0x2f4u;
    const U input=r.rdx;
    r.rcx=base;
    r=d.call_705c8(r);
    U index=low32(r.rax);
    if(index==0xffffffffu) {

        index=sign32(d.read(base+0x1204u,4u));
        r.rcx=input;
        U length=0;
        r.rdx=0xfffu;
        r.rax=low32(index+1u);
        d.write(base+0x1204u,4u,r.rax);

        do {
            set_al(r.rax,d.read(r.rcx,1u));
            ++r.rcx;
            if((r.rax&255u)==0u)break;
            ++length;
        } while(length<r.rdx);

        const U old_used=sign32(d.read(base+0x1000u,4u));
        r.rdx=low32(r.rdx-low32(old_used));
        r.r8=sign32(r.rdx);
        r.rdx=input;
        r.rcx=base+old_used;
        r=d.call_117b8(r);

        r.rax=low32(length+1u);
        const U now_used=d.read(base+0x1000u,4u);
        d.write(base+0x1000u,4u,low32(now_used+r.rax));
        d.write(base+index*2u+0x1004u,2u,old_used&65535u);
    }

    r.rax=low32(index);
    return r;
}

Registers sum_6c710(Memory& d,Registers r,U module_base) {
    r.rax=0;
    if(r.rcx==0u)return r;
    r.r9=sign32(d.read(r.rcx+0x228u,4u));
    if(r.r9==0u||(r.r9>>63u)!=0u)return r;
    r.rcx=low32(d.read(r.rcx+0x22cu,4u));
    r.r10=module_base+0x4e39f20u;
    r.r8=low32(r.rcx);
    r.rdx=low32(r.rcx);
    r.r8>>=28u;
    r.rcx=d.read(r.r10+r.r8*8u,8u);

    r.r8=r.rdx+2u;
    r.r8=r.rcx+r.r8*4u;
    do {
        r.rax=low32(r.rax+d.read(r.r8,4u));
        r.r8+=0x14u;
        --r.r9;
    } while(r.r9!=0u);
    return r;
}
}
