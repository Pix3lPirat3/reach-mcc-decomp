#pragma once

#include <cstdint>
#include <span>

namespace hum::reconstruction::reach {
using map_reset_address = std::uint64_t;

struct map_variant_reset_dependencies {
    virtual ~map_variant_reset_dependencies() = default;
    virtual void read_memory(map_reset_address, std::span<std::uint8_t>) = 0;
    virtual void write_memory(map_reset_address, std::span<const std::uint8_t>) = 0;

    virtual std::uint64_t fill_at_78932a(map_reset_address destination,
        std::uint32_t value_bits, std::uint64_t count) = 0;

    virtual map_reset_address identifier_at_3c5fc(map_reset_address scratch16,
        std::uint32_t identifier) = 0;

    virtual std::uint64_t apply_at_70434(map_reset_address variant) = 0;
};

std::uint64_t reset_map_variant_6c080(map_variant_reset_dependencies&,
    map_reset_address variant, std::uint32_t identifier,
    map_reset_address module_base, map_reset_address rbp);
}
