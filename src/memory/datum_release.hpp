#pragma once
#include <cstdint>

#include "../common/datum_lookup.hpp"

namespace hum::reconstruction::reach {

struct datum_release_memory : datum_lookup_memory {
    virtual std::uint8_t read8(datum_lookup_address) = 0;
    virtual void write16(datum_lookup_address, std::uint16_t) = 0;
    virtual void write32(datum_lookup_address, std::uint32_t) = 0;
};

inline constexpr std::uint64_t datum_release_stride_offset = 0x20;
inline constexpr std::uint64_t datum_release_flags_offset = 0x32;
inline constexpr std::uint64_t datum_release_hint_offset = 0x40;
inline constexpr std::uint64_t datum_release_bound_offset = 0x44;
inline constexpr std::uint64_t datum_release_count_offset = 0x48;
inline constexpr std::uint64_t datum_release_storage_offset = 0x50;
inline constexpr std::uint64_t datum_release_bitmap_offset = 0x58;
inline constexpr std::uint32_t datum_release_poison_bit = 3;
inline constexpr std::uint32_t datum_release_poison_value = 0xbabababau;
inline constexpr std::uint32_t datum_release_poison_byte = 0xbau;

struct datum_release_fill_dependency {
    virtual ~datum_release_fill_dependency() = default;
    virtual void fill_at_78932a(datum_lookup_address destination, std::uint32_t value_bits, std::uint64_t byte_count) = 0;
};

void release_datum_136f0(datum_release_memory&, datum_release_fill_dependency&, std::uint64_t array, std::uint32_t handle_bits);
}
