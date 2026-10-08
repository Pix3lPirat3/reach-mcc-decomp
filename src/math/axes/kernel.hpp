#pragma once

#include "../../map_variant/axes/decode_tail.hpp"
#include <optional>

namespace hum::reconstruction::reach::local1856c {
using address = recon1638::Address;
using vector_bits = recon1638::VectorBits;
using volatile_frame = recon1638::Frame;
using preserved_frame = recon1638::Preserved;

struct memory {
    virtual ~memory() = default;
    virtual std::uint32_t read32(address) = 0;
    virtual void write32(address, std::uint32_t) = 0;
};
struct completed_state {
    volatile_frame carriers;
    preserved_frame preserved;
    address restored_rsp;
};
enum class outcome { completed, fp_environment_refused };
struct result {
    outcome status;
    std::optional<completed_state> state;
};

result project(memory&, address module, address entry_rsp,
               volatile_frame incoming, preserved_frame original);
}
