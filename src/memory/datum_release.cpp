#include "datum_release.hpp"

namespace hum::reconstruction::reach {
namespace {
bool signed_less(std::uint32_t left, std::uint32_t right) {

    return (left ^ 0x80000000u) < (right ^ 0x80000000u);
}
}

void release_datum_136f0(datum_release_memory& memory, datum_release_fill_dependency& fill, std::uint64_t array,
    std::uint32_t handle_bits) {

    const std::uint64_t stride = memory.read64(array + datum_release_stride_offset);
    const std::uint8_t flags = memory.read8(array + datum_release_flags_offset);
    const std::uint32_t index32 = handle_bits & 0xffffu;
    const std::uint64_t index = index32;
    const std::uint64_t element = index * stride + memory.read64(array + datum_release_storage_offset);

    if (((flags >> datum_release_poison_bit) & 1u) != 0u) {
        if (stride > 0x20u || (element & 3u) != 0u || (stride & 3u) != 0u) {
            fill.fill_at_78932a(element, datum_release_poison_byte, stride);
        } else {
            const std::uint64_t dwords = stride >> 2u;
            for (std::uint64_t k = 0; k < dwords; ++k) {
                memory.write32(element + k * 4u, datum_release_poison_value);
            }
        }
    }

    const std::uint64_t bitmap = memory.read64(array + datum_release_bitmap_offset);
    const std::uint64_t word_address = bitmap + (index >> 5u) * 4u;
    const std::uint32_t bit = 1u << (index32 & 31u);
    const std::uint32_t old_word = memory.read32(word_address);
    memory.write32(word_address, old_word & ~bit);

    memory.write16(element, 0u);

    const std::uint32_t hint = memory.read32(array + datum_release_hint_offset);
    if (signed_less(index32, hint)) memory.write32(array + datum_release_hint_offset, index32);

    const std::uint32_t next = index32 + 1u;
    const std::uint32_t bound = memory.read32(array + datum_release_bound_offset);
    if (next == bound) {
        std::uint64_t cursor = element;
        for (;;) {
            cursor -= memory.read64(array + datum_release_stride_offset);
            const std::uint32_t reduced = memory.read32(array + datum_release_bound_offset) - 1u;
            memory.write32(array + datum_release_bound_offset, reduced);
            const std::uint32_t current = memory.read32(array + datum_release_bound_offset);
            if (!signed_less(0u, current)) break;
            if (memory.read16(cursor) != 0u) break;
        }
    }

    const std::uint32_t count = memory.read32(array + datum_release_count_offset);
    memory.write32(array + datum_release_count_offset, count - 1u);
}
}
