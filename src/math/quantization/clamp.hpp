#pragma once
#include <cstdint>
namespace hum::recon639 {
struct Registers {
    std::uint64_t rax,rcx,rdx,r8,r9,r10,r11,rbx,rsi,rdi,rbp,r12,r13,r14,r15;
    bool operator==(const Registers&) const = default;
};
struct Memory {
    virtual ~Memory() = default;
    virtual std::uint32_t read32(std::uint64_t) = 0;
    virtual void write32(std::uint64_t,std::uint32_t) = 0;
};

Registers triplet_clamp639(Memory&,Registers);
}
