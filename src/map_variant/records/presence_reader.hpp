#pragma once
#include <cstdint>

namespace recon1703 {
struct Registers {
    std::uint64_t rax, rcx, rdx, r8, r9, r10, r11;
};
struct Memory {
    virtual ~Memory() = default;
    virtual std::uint8_t read8(std::uint64_t) = 0;
    virtual std::uint32_t read32(std::uint64_t) = 0;
    virtual std::uint64_t read64(std::uint64_t) = 0;
    virtual void write32(std::uint64_t, std::uint32_t) = 0;
    virtual void write64(std::uint64_t, std::uint64_t) = 0;
};

Registers read_flag(Memory&, Registers);
}
