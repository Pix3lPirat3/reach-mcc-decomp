#pragma once
#include "../../../bitstream/native_writer.hpp"
#include <array>
namespace hum::reconstruction::reach {
struct registers570 {
    std::uint64_t rax,rcx,rdx,r8,r9,r10,r11;
    bool operator==(const registers570&) const = default;
};
struct comparison570 {
    registers570 gpr;
    std::array<std::uint32_t,6> xmm_scalar_bits;
    bool operator==(const comparison570&) const = default;
};

comparison570 compare_triplet570(native_bitstream_writer_memory& memory,
    registers570 incoming,std::uint64_t constant_address);
}
