#pragma once
#include <cstdint>

namespace hum::reconstruction::reach {
using native_bitstream_address = std::uint64_t;

struct native_bitstream_writer_memory {
    virtual ~native_bitstream_writer_memory() = default;
    virtual std::uint16_t read16(native_bitstream_address address) = 0;
    virtual std::uint32_t read32(native_bitstream_address address) = 0;
    virtual std::uint64_t read64(native_bitstream_address address) = 0;
    virtual void write8(native_bitstream_address address,std::uint8_t bits) = 0;
    virtual void write32(native_bitstream_address address,std::uint32_t bits) = 0;
    virtual void write64(native_bitstream_address address,std::uint64_t bits) = 0;
};

struct native_bitstream_writer_continuation {
    std::uint64_t rdx_bits;
    std::uint64_t r11_bits;
};

native_bitstream_writer_continuation flush_native_bitstream(
    native_bitstream_writer_memory& memory,native_bitstream_address stream,
    std::uint64_t value_bits,std::uint32_t width,std::uint64_t incoming_r11);

native_bitstream_writer_continuation write_native_bitstream_fields128(
    native_bitstream_writer_memory& memory,native_bitstream_address stream,
    native_bitstream_address source,std::uint64_t ignored_incoming_rdx);
}
