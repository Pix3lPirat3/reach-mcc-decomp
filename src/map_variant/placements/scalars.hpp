#pragma once
#include "../../bitstream/native_writer.hpp"
#include <array>
#include <cstdint>

namespace hum::reconstruction::reach::placement_scalars {
using address = std::uint64_t;
struct memory : native_bitstream_writer_memory {
    virtual std::uint8_t read8(address) = 0;
    virtual std::array<std::uint8_t,16> read128(address) = 0;
};

struct continuation { std::uint32_t xmm0_low; std::uint64_t token; };
struct boundary {
    address stream;
    std::uint32_t xmm0_low, xmm1_low, xmm2_low, xmm3_low;
    std::uint32_t stack20_low, stack28;
    std::uint8_t stack30_low, stack38_low;
};
struct imports {
    virtual ~imports() = default;

    virtual continuation dc234(memory&, const boundary&, continuation) = 0;

    virtual std::uint64_t writer_effect(continuation,
        native_bitstream_writer_continuation) = 0;
};

continuation scalar(memory&, imports&, address module, address stream,
                    std::uint32_t xmm2_low, continuation);
continuation record(memory&, imports&, address module, address source,
                    address stream, continuation, std::uint64_t incoming_r11);
}
