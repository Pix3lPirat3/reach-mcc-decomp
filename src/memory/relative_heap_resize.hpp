#pragma once

#include <cstdint>

namespace hum::reconstruction::reach {
using heap_resize_address = std::uint64_t;

constexpr std::uint64_t heap_pool_flags_offset = 0x04;
constexpr std::uint64_t heap_pool_callback_offset = 0x30;
constexpr std::uint64_t heap_pool_region_offset = 0x38;
constexpr std::uint64_t heap_pool_free_total_offset = 0x40;
constexpr std::uint64_t heap_pool_base_offset = 0x48;
constexpr std::uint64_t heap_pool_cursor_offset = 0x54;

constexpr std::uint64_t heap_block_size_offset = 0x00;
constexpr std::uint64_t heap_block_tag_offset = 0x04;
constexpr std::uint64_t heap_block_next_offset = 0x08;
constexpr std::uint64_t heap_block_link_offset = 0x0c;
constexpr std::uint32_t heap_block_header_size = 0x10;

struct relative_heap_resize_dependencies {
    virtual ~relative_heap_resize_dependencies() = default;
    virtual std::uint8_t read8(heap_resize_address) = 0;
    virtual std::uint32_t read32(heap_resize_address) = 0;
    virtual std::uint64_t read64(heap_resize_address) = 0;
    virtual void write32(heap_resize_address, std::uint32_t) = 0;
    virtual void write64(heap_resize_address, std::uint64_t) = 0;

    virtual std::uint32_t allocate(heap_resize_address pool, std::uint32_t tag, std::uint64_t size) = 0;

    virtual void copy_bytes(heap_resize_address destination, heap_resize_address source, std::uint64_t count) = 0;

    virtual void free_block(heap_resize_address pool, std::uint32_t offset) = 0;

    virtual void relocation_callback(heap_resize_address callback, std::uint32_t tag, std::uint32_t new_offset) = 0;
};

std::uint32_t resize_relative_heap_block(relative_heap_resize_dependencies& dependencies,
                                         heap_resize_address pool, std::uint32_t offset, std::uint64_t size);
}
