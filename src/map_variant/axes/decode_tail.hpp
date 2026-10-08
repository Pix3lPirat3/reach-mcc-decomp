#pragma once
#include <array>
#include <cstdint>

namespace hum::reconstruction::reach::recon1638 {
using Address = std::uint64_t;
using VectorBits = std::array<std::uint32_t, 4>;
struct Frame {
    std::uint64_t rax, rcx, rdx, r8, r9, r10, r11;
    std::array<VectorBits, 6> xmm;
};
struct Preserved {
    std::uint64_t rbx, rbp, rsi, rdi, r12, r13, r14, r15;
    std::array<VectorBits, 10> xmm;
};
struct Dependencies {
    virtual ~Dependencies() = default;
    virtual std::uint32_t read32(Address) = 0;
    virtual std::uint64_t read64(Address) = 0;
    virtual void write32(Address, std::uint32_t) = 0;
    virtual void write64(Address, std::uint64_t) = 0;

    virtual Frame call(std::uint32_t target_rva, std::uint32_t callsite_rva,
        Frame, const Preserved&) = 0;

    virtual Frame tail_1fcfc(Frame, const Preserved& restored, Address rsp_token) = 0;
};

Frame tail_dc198(Dependencies&, Address module, Address native_entry_rsp,
    Frame incoming, Preserved entry_preserved);
}
