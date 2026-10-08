#pragma once
#include <cstdint>
#include <optional>

#include "../common/datum_lookup.hpp"

namespace hum::reconstruction::reach {

struct datum_allocation_memory : datum_lookup_memory {
    virtual void write16(datum_lookup_address, std::uint16_t) = 0;
    virtual void write32(datum_lookup_address, std::uint32_t) = 0;
};

inline constexpr std::uint64_t datum_alloc_stride_offset = 0x20;
inline constexpr std::uint64_t datum_alloc_limit_offset = 0x2c;
inline constexpr std::uint64_t datum_alloc_hint_offset = 0x40;
inline constexpr std::uint64_t datum_alloc_bound_offset = 0x44;
inline constexpr std::uint64_t datum_alloc_count_offset = 0x48;
inline constexpr std::uint64_t datum_alloc_counter_offset = 0x4c;
inline constexpr std::uint64_t datum_alloc_storage_offset = 0x50;
inline constexpr std::uint64_t datum_alloc_bitmap_offset = 0x58;
inline constexpr std::uint32_t datum_alloc_failure = 0xffffffffU;

struct datum_initializer_call {
    std::uint64_t array;
    std::uint64_t element;
    std::uint64_t counter_address;
    std::uint64_t r9, r10, r11;
    std::uint32_t index;
};

struct datum_initializer_result {
    std::optional<std::uint64_t> rax, rcx, rdx, r8, r9, r10, r11;
    bool operator==(const datum_initializer_result&) const = default;
};

struct datum_initializer_138f0 {
    virtual ~datum_initializer_138f0() = default;
    virtual datum_initializer_result initialize(datum_allocation_memory&, const datum_initializer_call&) = 0;
};

struct datum_allocation_result {
    std::uint32_t handle;
    std::uint64_t rax, rdx;
    std::optional<std::uint64_t> rcx, r8, r9, r10, r11;
    bool initializer_called;
    bool operator==(const datum_allocation_result&) const = default;
};

datum_allocation_result allocate_datum_13464(datum_allocation_memory&, datum_initializer_138f0&,
    std::uint64_t array, std::uint64_t incoming_r11);

struct datum_fill_dependency {
    virtual ~datum_fill_dependency() = default;
    virtual void fill_at_78932a(datum_lookup_address destination, std::uint32_t value_bits, std::uint64_t byte_count) = 0;
};

class datum_element_initializer_138f0 final : public datum_initializer_138f0 {
public:
    explicit datum_element_initializer_138f0(datum_fill_dependency& fill) : fill_(fill) {}
    datum_initializer_result initialize(datum_allocation_memory&, const datum_initializer_call&) override;
private:
    datum_fill_dependency& fill_;
};
}
