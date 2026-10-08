#pragma once
#include "identifier_codec.hpp"
#include <span>

namespace hum::reconstruction::reach::position_composition03 {
using address = std::uint64_t;
struct memory : native_bitstream_writer_memory, security_cookie_memory {
    virtual std::uint8_t read8(address) = 0;
    virtual std::uint64_t read64(address) override = 0;
};
struct extent { address begin, size; };
struct admission {
    address module, classifier_private_token;
    std::span<const extent> initialized_guest_extents;
};

identifier_codec410::encode_result encode(memory&, const admission&,
    address stream, address point, std::uint32_t width, address optional_bounds,
    identifier_codec410::workspace);
}
