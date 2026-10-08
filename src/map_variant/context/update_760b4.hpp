#pragma once
#include "getter.hpp"
#include "../lookups/lookup_6cf60.hpp"
#include <cstdint>

namespace recon457 {
using address=std::uint64_t;
struct registers {
    address rax,rcx,rdx,r8,r9,r10,r11;
    bool operator==(const registers&) const = default;
};
struct memory : recon453::Memory, recon453::Dependency {
    virtual ~memory()=default;
    std::uint8_t read8(address a) {return static_cast<std::uint8_t>(read(a,1));}
    std::uint32_t read32(address a) {return static_cast<std::uint32_t>(read(a,4));}
    address read64(address a) {return read(a,8);}
    void write8(address a,std::uint8_t x) {write(a,1,x);}
    virtual address read_gs64(std::uint32_t)=0;

    virtual registers call_71540(registers)=0;
    virtual registers call_6dd80(registers)=0;
    virtual registers call_3a5be8(registers)=0;

};

registers getter_6bcec(memory&,address module,registers);

registers body_760b4(memory&,address module,address working_rsp,registers);
}
