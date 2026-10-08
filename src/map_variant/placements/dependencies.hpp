#pragma once
#include <cstdint>

namespace recon1552 {
using U=std::uint64_t;
struct Registers { U rax,rcx,rdx,r8,r9,r10,r11; };
struct Memory {
    virtual ~Memory()=default;

    virtual U read(U address,unsigned width)=0;
    virtual void write(U address,unsigned width,U value)=0;
};
struct StringDependencies : Memory {

    virtual Registers call_705c8(Registers)=0;
    virtual Registers call_117b8(Registers)=0;
};

Registers append_6bb70(StringDependencies&,Registers,U native_entry_rsp);
Registers sum_6c710(Memory&,Registers,U module_base);
}
