#pragma once
#include "integer_reader.hpp"

namespace hum::reconstruction::reach::reader_revision324_detail {

std::uint64_t read_guid_fixed64(native_bitstream_reader_memory&,
    native_bitstream_reader_address reader, native_bitstream_reader_private_input&);
}
