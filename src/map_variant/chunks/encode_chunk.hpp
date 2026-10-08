#pragma once
#include "../../bitstream/setup.hpp"
#include "../../bitstream/finalize.hpp"
#include "../../security/hash.hpp"

namespace hum::reconstruction::reach::chunk_encoder477 {
using address = std::uint64_t;

struct dependencies : bitstream_setup_memory, bitstream_finalize_memory,
                      crypto_hash_wrappers::dependencies {
    virtual std::uint32_t read32(address location) override = 0;
    virtual std::uint64_t read64(address location) override = 0;
    virtual void write8(address location, std::uint8_t value) override = 0;
    virtual void write32(address location, std::uint32_t value) override = 0;
    virtual void write64(address location, std::uint64_t value) override = 0;

    virtual void encode_variant_6d04c(address variant, address stream) = 0;
};

struct workspace { address frame_rsp; };

std::uint64_t encode(dependencies& memory, address module_base, address chunk,
                     address variant, workspace frame);
}
