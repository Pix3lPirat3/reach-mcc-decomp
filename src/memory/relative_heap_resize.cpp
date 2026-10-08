#include "relative_heap_resize.hpp"

namespace hum::reconstruction::reach {
std::uint32_t resize_relative_heap_block(relative_heap_resize_dependencies& d, heap_resize_address pool,
                                         std::uint32_t offset, std::uint64_t size) {

    const std::uint64_t flag = d.read8(pool + heap_pool_flags_offset) & 1u;
    const std::uint64_t rounded = ((size + 0x1f) + (flag << 5)) & ~std::uint64_t{0xf};

    const std::uint32_t header_offset = offset - heap_block_header_size;
    const heap_resize_address header = pool + header_offset;

    if (header_offset == d.read32(pool + heap_pool_cursor_offset))
        d.write32(pool + heap_pool_cursor_offset, d.read32(header + heap_block_link_offset));

    const std::uint32_t current = d.read32(header + heap_block_size_offset);

    if (rounded == current) return offset;

    if (size == 0) {
        d.free_block(pool, offset);
        return 0;
    }

    std::uint32_t limit_offset = d.read32(header + heap_block_next_offset);
    if (limit_offset == 0) {
        const std::uint64_t region = d.read64(pool + heap_pool_region_offset);
        limit_offset = d.read32(pool + heap_pool_base_offset) + static_cast<std::uint32_t>(region);
    }

    if (header + rounded <= pool + limit_offset) {

        d.write64(pool + heap_pool_free_total_offset,
                  d.read64(pool + heap_pool_free_total_offset) + (static_cast<std::uint64_t>(current) - rounded));
        d.write32(header + heap_block_size_offset, static_cast<std::uint32_t>(rounded));
        if (offset != 0) return offset;
    }

    const std::uint32_t tag = d.read32(header + heap_block_tag_offset);
    const std::uint32_t fresh = d.allocate(pool, tag, size);
    if (fresh == 0) return 0;

    const std::uint64_t flag_again = d.read8(pool + heap_pool_flags_offset) & 1u;
    const std::uint64_t count = static_cast<std::uint64_t>(d.read32(header + heap_block_size_offset)) - (flag_again << 5) - heap_block_header_size;
    d.copy_bytes(pool + fresh, pool + offset, count);

    d.free_block(pool, offset);

    const std::uint64_t callback = d.read64(pool + heap_pool_callback_offset);
    if (callback != 0) {
        const std::uint32_t new_header_offset = fresh - heap_block_header_size;
        const std::uint32_t new_tag = d.read32(pool + new_header_offset + heap_block_tag_offset);
        d.relocation_callback(callback, new_tag, new_header_offset + heap_block_header_size);
    }
    return fresh;
}
}
