#pragma once
#include <cstdint>

namespace hum::reconstruction::reach {
using datum_lookup_address = std::uint64_t;

struct datum_lookup_memory {
    virtual ~datum_lookup_memory() = default;
    virtual std::uint16_t read16(datum_lookup_address) = 0;
    virtual std::uint32_t read32(datum_lookup_address) = 0;
    virtual std::uint64_t read64(datum_lookup_address) = 0;
};

datum_lookup_address lookup_datum_handle(datum_lookup_memory&,
    datum_lookup_address array, std::uint32_t handle_bits);

}
