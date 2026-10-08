#pragma once
#include "../../bitstream/integer_reader.hpp"
#include <array>
#include <cstdint>
#include <optional>
#include <span>
namespace hum::reconstruction::reach::position_reduced {
using address=std::uint64_t;
struct memory:native_bitstream_reader_memory {
    virtual std::uint16_t read16(address)=0;
    virtual void write8(address,std::uint8_t)=0;
};
struct extent {address begin,size;};
struct admission {
    address module,frame,bounds;
    std::span<const extent> initialized_guest;
};
enum class outcome {completed,domain_refused,fp_refused,nonfinite_refused,
    scalar_home_refused,cookie_tail_refused,excluded_path_refused};
struct result {
    outcome status;
    std::optional<std::array<std::uint32_t,3>> output_bits;
    std::optional<std::uint64_t> rdx_bits;
};

result decode(memory&,const admission&,address reader,address output);
}
