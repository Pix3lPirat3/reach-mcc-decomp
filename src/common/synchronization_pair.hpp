#pragma once
#include <cstdint>

namespace hum::reconstruction::reach::synchronization_pair {
using address=std::uint64_t;

struct carriers {
    std::uint64_t rax,rcx,rdx,r8,r9,r10,r11;
    bool operator==(const carriers&)const=default;
};
struct dependencies {
    virtual ~dependencies()=default;
    virtual std::uint32_t read32(address)=0;
    virtual std::uint64_t read64(address)=0;
    virtual std::uint64_t read_gs64(std::uint32_t displacement)=0;
    virtual carriers gate_enter_1398c(carriers)=0;
    virtual carriers gate_exit_13aa8(carriers)=0;

    virtual carriers enter_critical_section(address target,carriers)=0;
    virtual carriers leave_critical_section(address target,carriers)=0;

    virtual std::uint32_t exchange32(address,std::uint32_t value)=0;
    virtual void locked_increment32(address)=0;
    virtual void locked_decrement32(address)=0;
};

carriers enter_12c44(dependencies&,address module,carriers incoming);
carriers leave_12d40(dependencies&,address module,carriers incoming);
}
