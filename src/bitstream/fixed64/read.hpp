#pragma once
#include "../integer_reader.hpp"

namespace hum::reconstruction::reach::recon2956 {

native_bitstream_reader_continuation read_fixed64(
    native_bitstream_reader_memory& memory, std::uint64_t reader,
    std::uint64_t incoming_rdx, native_bitstream_reader_private_input& home);
}
