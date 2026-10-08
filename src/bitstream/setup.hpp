#pragma once
#include <cstdint>

namespace hum::reconstruction::reach {
using bitstream_setup_address = std::uint64_t;

struct bitstream_setup_memory {
    virtual ~bitstream_setup_memory() = default;
    virtual std::uint8_t read8(bitstream_setup_address address) = 0;
    virtual std::uint32_t read32(bitstream_setup_address address) = 0;
    virtual std::uint64_t read64(bitstream_setup_address address) = 0;
    virtual void write8(bitstream_setup_address address, std::uint8_t bits) = 0;
    virtual void write32(bitstream_setup_address address, std::uint32_t bits) = 0;
    virtual void write64(bitstream_setup_address address, std::uint64_t bits) = 0;
};

struct bitstream_setup_input {
    std::uint64_t rax_bits;
    std::uint64_t rdx_bits;
    std::uint64_t r10_bits;
    std::uint64_t r11_bits;
    bitstream_setup_address entry_rsp;
};

struct bitstream_setup_continuation {
    std::uint64_t rax_bits, rcx_bits, rdx_bits, r8_bits;
    std::uint64_t r9_bits, r10_bits, r11_bits;
};

bitstream_setup_continuation setup_bitstream(
    bitstream_setup_memory& memory, bitstream_setup_address stream,
    bitstream_setup_input input);
}
