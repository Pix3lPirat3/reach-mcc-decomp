#pragma once
#include <cstdint>
#include "../../bitstream/integer_reader.hpp"

namespace hum::reconstruction::reach::recon2902_r2 {
using address = std::uint64_t;

struct call_result { std::uint64_t rax_bits; std::uint64_t rdx_bits; };

struct metadata_object_callback {
    virtual ~metadata_object_callback() = default;
    virtual call_result call_103968(address reader, address target) = 0;
};

struct metadata_span_callback {
    virtual ~metadata_span_callback() = default;
    virtual call_result call_dc5fc(address reader, std::uint64_t carried_rdx,
        address span, std::uint32_t length) = 0;
};

struct metadata_record_memory {
    virtual ~metadata_record_memory() = default;
    virtual std::uint8_t read8(address) = 0;
    virtual void write8(address, std::uint8_t) = 0;
    virtual void write16(address, std::uint16_t) = 0;
    virtual void write32(address, std::uint32_t) = 0;
    virtual void write64(address, std::uint64_t) = 0;
};

struct metadata_decoder_dependencies : metadata_object_callback, metadata_span_callback,
    metadata_record_memory, native_bitstream_reader_memory, native_bitstream_reader_private_input {
    virtual ~metadata_decoder_dependencies() = default;
    using native_bitstream_reader_memory::read8;
    using native_bitstream_reader_memory::write32;
    using native_bitstream_reader_memory::write64;
};

struct metadata_decoder_result { std::uint64_t rdx_bits; };
metadata_decoder_result decode_metadata_103638(metadata_decoder_dependencies&, address reader, address variant);
}
