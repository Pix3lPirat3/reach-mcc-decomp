#pragma once
#include "native_writer.hpp"

namespace hum::reconstruction::reach {

native_bitstream_writer_continuation write_optional_code523(
    native_bitstream_writer_memory& memory,native_bitstream_address stream,
    std::uint32_t raw_value);
}
