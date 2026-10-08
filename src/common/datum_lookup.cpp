#include "datum_lookup.hpp"

namespace hum::reconstruction::reach {
datum_lookup_address lookup_datum_handle(datum_lookup_memory& memory,
    datum_lookup_address array, std::uint32_t handle_bits) {

    if (handle_bits == 0xffffffffU) return 0;
    const std::uint32_t index = handle_bits & 0xffffU;
    const std::uint32_t upper_bits = memory.read32(array + 0x44U);

    if ((upper_bits & 0x80000000U) != 0 || index >= upper_bits) return 0;

    const std::uint64_t stride = memory.read64(array + 0x20U);
    const datum_lookup_address storage = memory.read64(array + 0x50U);
    const datum_lookup_address datum = stride * std::uint64_t{index} + storage;

    if (memory.read16(datum) == 0) return 0;
    const std::uint16_t expected_salt =
        static_cast<std::uint16_t>(handle_bits >> 16);
    return memory.read16(datum) == expected_salt ? datum : 0;
}
}
