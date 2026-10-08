#pragma once
#include <cstdint>

namespace hum::reconstruction::reach {
using bitstream_finalize_address = std::uint64_t;

struct bitstream_finalize_memory {
    virtual ~bitstream_finalize_memory() = default;
    virtual std::uint32_t read32(bitstream_finalize_address address) = 0;
    virtual std::uint64_t read64(bitstream_finalize_address address) = 0;
    virtual void write8(bitstream_finalize_address address, std::uint8_t bits) = 0;
    virtual void write32(bitstream_finalize_address address, std::uint32_t bits) = 0;
    virtual void write64(bitstream_finalize_address address, std::uint64_t bits) = 0;
};

struct bitstream_finalize_continuation {
    std::uint64_t rax_bits, rcx_bits, rdx_bits, r8_bits;
    std::uint64_t r9_bits, r10_bits, r11_bits;
};

bitstream_finalize_continuation finalize_bitstream(
    bitstream_finalize_memory& memory, bitstream_finalize_address stream);
}
