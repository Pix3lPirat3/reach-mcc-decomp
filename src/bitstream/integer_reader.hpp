#pragma once
#include <cstdint>
#include <array>

namespace hum::reconstruction::reach {
using native_bitstream_reader_address = std::uint64_t;

struct native_bitstream_reader_memory {
    virtual ~native_bitstream_reader_memory() = default;
    virtual std::uint8_t read8(native_bitstream_reader_address) = 0;
    virtual std::uint32_t read32(native_bitstream_reader_address) = 0;
    virtual std::uint64_t read64(native_bitstream_reader_address) = 0;
    virtual void write32(native_bitstream_reader_address, std::uint32_t) = 0;
    virtual void write64(native_bitstream_reader_address, std::uint64_t) = 0;
};

struct native_bitstream_reader_private_input {
    virtual ~native_bitstream_reader_private_input() = default;
    virtual std::uint32_t empty_refill_caller_home_word() = 0;
};
struct native_bitstream_reader_continuation {
    std::uint64_t rax_bits;
    std::uint64_t rdx_bits;
    std::uint64_t r11_bits;
    bool operator==(const native_bitstream_reader_continuation&) const = default;
};

native_bitstream_reader_continuation read_native_bitstream_integer(
    native_bitstream_reader_memory&, native_bitstream_reader_address reader,
    std::uint64_t incoming_rdx, native_bitstream_reader_private_input&);

struct native_bitstream_reader_context {
    std::uint64_t rax_bits,rcx_bits,rdx_bits,r8_bits,r9_bits,r10_bits,r11_bits;
    std::array<std::array<std::uint32_t,4>,6> xmm_bits;
    bool operator==(const native_bitstream_reader_context&) const = default;
};

native_bitstream_reader_context read_native_bitstream_integer_context(
    native_bitstream_reader_memory&,native_bitstream_reader_context incoming,
    native_bitstream_reader_private_input&);
}
