#pragma once
#include "presence_reader.hpp"

namespace recon1703::flag_shared_detail {
inline std::uint64_t sign_extend32(std::uint32_t value) {
    return (value & 0x80000000u) != 0 ? (0xffffffff00000000ull | value) : value;
}
inline std::uint64_t reverse_bytes(std::uint64_t value) {
    std::uint64_t result = 0;
    for (unsigned i = 0; i != 8; ++i) {
        result = (result << 8) | (value & 0xffu);
        value >>= 8;
    }
    return result;
}
template<class Memory,class State>
State read_flag_core(Memory& memory,State r) {
    const auto incoming_edx = static_cast<std::uint32_t>(r.rdx);
    auto count = memory.read32(r.rcx + 0x30);
    r.r10 = r.rcx;
    r.r11 = memory.read64(r.rcx + 0x28);
    if (count < 64u) {
        memory.write32(r.r10 + 0x24, memory.read32(r.r10 + 0x24) + 1u);
        r.rax = r.r11 + r.r11;
        r.rcx = r.r11 >> 63;
        ++count;
    } else {
        r.rcx = memory.read64(r.rcx + 0x38);
        r.r9 = 0;
        r.r8 = r.rcx + 8u;
        if (r.r8 <= memory.read64(r.r10 + 8u)) {
            r.rdx = memory.read64(r.rcx);
            memory.write64(r.r10 + 0x38, r.r8);

            r.r9 = reverse_bytes(r.rdx);
            r.rdx = 64;
        } else if (r.rcx < memory.read64(r.r10 + 8u)) {
            r.rdx = static_cast<std::uint32_t>(r.r9);
            do {
                r.rax = memory.read8(r.rcx);
                r.rdx = static_cast<std::uint32_t>(r.rdx + 8u);
                r.r9 <<= 8;
                ++r.rcx;
                r.r9 |= r.rax;
                memory.write64(r.r10 + 0x38, r.rcx);
            } while (r.rcx < memory.read64(r.r10 + 8u));
            r.rcx = 64;
            r.rcx = (r.rcx & ~0xffull) |
                static_cast<std::uint8_t>(r.rcx - r.rdx);
            r.r9 <<= (r.rcx & 63u);
        } else {
            r.rdx = incoming_edx;
        }
        memory.write32(r.r10 + 0x20,
            memory.read32(r.r10 + 0x20) + static_cast<std::uint32_t>(r.rdx));
        count += 0xffffffc1u;
        memory.write32(r.r10 + 0x24, memory.read32(r.r10 + 0x24) + 1u);
        r.rdx = r.r9;
        r.rcx = count;
        r.r8 = sign_extend32(count);
        r.rdx <<= (r.rcx & 63u);
        r.rcx = 64;
        const auto mask = r.r8 < 64u ? ~std::uint64_t{0} : std::uint64_t{0};
        r.rcx = (r.rcx & ~0xffull) | static_cast<std::uint8_t>(r.rcx - r.r8);
        r.r9 >>= (r.rcx & 63u);
        r.rax = mask & r.rdx;
        r.r11 >>= 63;
        r.r9 |= r.r11;
        r.rcx = (r.rcx & ~0xffull) | static_cast<std::uint8_t>(r.r9 != 0);
    }
    memory.write64(r.r10 + 0x28, r.rax);
    r.rax = (r.rax & ~0xffull) | (r.rcx & 0xffu);
    memory.write32(r.r10 + 0x30, count);
    return r;
}
}
