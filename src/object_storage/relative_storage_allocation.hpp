#pragma once

#include <cstdint>

namespace hum::reconstruction::reach {
using object_storage_address = std::uint64_t;

constexpr std::uint64_t object_entry_stride = 24;
constexpr std::uint64_t object_entry_size_word_offset = 6;
constexpr std::uint64_t object_entry_pool_offset_offset = 8;
constexpr std::uint64_t object_entry_payload_offset = 0x10;

struct relative_storage_request {
    std::uint32_t object_handle;
    std::uint16_t descriptor_offset;
    std::uint16_t size;
    std::uint8_t alignment_exponent;
};

struct relative_storage_dependencies {
    virtual ~relative_storage_dependencies() = default;
    virtual std::uint16_t read16(object_storage_address) = 0;
    virtual std::uint32_t read32(object_storage_address) = 0;
    virtual std::uint64_t read64(object_storage_address) = 0;
    virtual void write16(object_storage_address, std::uint16_t) = 0;
    virtual void write32(object_storage_address, std::uint32_t) = 0;
    virtual void write64(object_storage_address, std::uint64_t) = 0;

    virtual object_storage_address object_entry_table() = 0;

    virtual object_storage_address object_pool() = 0;

    virtual std::uint32_t pool_resize(object_storage_address pool, std::uint32_t offset,
                                      std::uint64_t byte_count) = 0;

    virtual void fill(object_storage_address destination, std::uint32_t value, std::uint64_t byte_count) = 0;
};

bool allocate_relative_storage(relative_storage_dependencies& dependencies,
                               const relative_storage_request& request);
}
