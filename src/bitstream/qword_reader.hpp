#pragma once
#include "integer_reader.hpp"

namespace hum::reconstruction::reach {

native_bitstream_reader_continuation read_native_bitstream_qword(
    native_bitstream_reader_memory&, native_bitstream_reader_address reader,
    std::uint64_t incoming_rdx, native_bitstream_reader_private_input&);
}
