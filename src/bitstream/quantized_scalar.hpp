#pragma once
#include "native_writer.hpp"
namespace hum::reconstruction::reach::recon671 {
struct Memory : native_bitstream_writer_memory {
    virtual std::uint8_t read8(std::uint64_t address) = 0;
};
struct Entry { std::uint64_t stream, rsp; float xmm2, xmm3; };
struct Result { std::uint32_t payload; std::uint64_t rdx, r11; bool tail; };

Result body_dc234(Memory&, Entry);
}
