#pragma once
#include "../../bitstream/integer_reader.hpp"
#include <cstdint>

namespace hum::reconstruction::reach::recon2904 {
using address = native_bitstream_reader_address;

struct metadata_children_memory : native_bitstream_reader_memory {
    virtual void write8(address, std::uint8_t) = 0;
    virtual void write16(address, std::uint16_t) = 0;
};

struct metadata_children_continuation {
    std::uint64_t rax_bits;
    std::uint64_t rdx_bits;
};

struct metadata_children_imports {
    virtual ~metadata_children_imports() = default;

    virtual metadata_children_continuation call_dd274(address reader) = 0;

    virtual metadata_children_continuation call_memset_78932a(
        address destination, std::uint32_t value, std::uint64_t count) = 0;
};

metadata_children_continuation write_byte_string_dc574(metadata_children_memory&,
    metadata_children_imports&, address reader, address destination,
    std::int32_t length, native_bitstream_reader_private_input&,
    std::uint64_t entry_rdx_bits);

metadata_children_continuation write_utf16_string_dc5fc(metadata_children_memory&,
    metadata_children_imports&, address reader, address destination,
    std::int32_t length, native_bitstream_reader_private_input&,
    std::uint64_t entry_rdx_bits);

metadata_children_continuation write_metadata_object_children_103968(
    metadata_children_memory&, metadata_children_imports&, address reader,
    address destination, native_bitstream_reader_private_input&);
}
