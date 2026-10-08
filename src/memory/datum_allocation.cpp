#include "datum_allocation.hpp"

namespace hum::reconstruction::reach {
namespace {
bool signed_less(std::uint32_t left, std::uint32_t right) {

    return (left ^ 0x80000000u) < (right ^ 0x80000000u);
}
std::uint64_t sign_extend32(std::uint32_t value) {
    return (value & 0x80000000u) != 0u ? static_cast<std::uint64_t>(value) | 0xffffffff00000000ULL : value;
}

datum_allocation_result failure(std::uint64_t rcx, std::uint32_t bound, std::uint64_t array, std::uint64_t bitmap,
    std::uint64_t incoming_r11) {

    return datum_allocation_result{datum_alloc_failure, 0xffffffffULL, 0xffffffffULL, rcx, bound, array, bitmap,
        incoming_r11, false};
}
}

datum_allocation_result allocate_datum_13464(datum_allocation_memory& memory, datum_initializer_138f0& initializer,
    std::uint64_t array, std::uint64_t incoming_r11) {

    const std::uint64_t bitmap = memory.read64(array + datum_alloc_bitmap_offset);
    const std::uint32_t bound = memory.read32(array + datum_alloc_bound_offset);
    std::uint32_t index = memory.read32(array + datum_alloc_hint_offset);
    std::uint64_t rcx = array;

    bool free_slot = false;
    while (signed_less(index, bound)) {
        rcx = index & 31u;
        const std::uint32_t word = memory.read32(bitmap + static_cast<std::uint64_t>(index >> 5u) * 4u);
        if (((word >> rcx) & 1u) == 0u) {
            free_slot = true;
            break;
        }
        ++index;
    }

    if (!free_slot || index == 0xffffffffu) {

        const std::uint32_t limit = memory.read32(array + datum_alloc_limit_offset);
        if (!signed_less(bound, limit)) return failure(rcx, bound, array, bitmap, incoming_r11);
        index = bound;
        if (bound == 0xffffffffu) return failure(rcx, bound, array, bitmap, incoming_r11);
    }

    const std::uint64_t stride = memory.read64(array + datum_alloc_stride_offset);
    const std::uint64_t scaled = stride * sign_extend32(index);
    const std::uint32_t next = index + 1u;
    const std::uint64_t element = scaled + memory.read64(array + datum_alloc_storage_offset);

    const std::uint64_t word_address = bitmap + static_cast<std::uint64_t>(index >> 5u) * 4u;
    const std::uint32_t old_word = memory.read32(word_address);
    memory.write32(word_address, old_word | (1u << (index & 31u)));

    const std::uint32_t count = memory.read32(array + datum_alloc_count_offset);
    memory.write32(array + datum_alloc_count_offset, count + 1u);

    memory.write32(array + datum_alloc_hint_offset, next);

    const std::uint32_t current_bound = memory.read32(array + datum_alloc_bound_offset);
    if (!signed_less(index, current_bound)) memory.write32(array + datum_alloc_bound_offset, next);

    const datum_initializer_call call{array, element, array + datum_alloc_counter_offset, array, bitmap, incoming_r11,
        index};
    const datum_initializer_result after = initializer.initialize(memory, call);

    const std::uint16_t halfword = memory.read16(element);
    const std::uint32_t handle = (static_cast<std::uint32_t>(halfword) << 16) | index;

    return datum_allocation_result{handle, handle, handle, after.rcx, after.r8, after.r9, after.r10, after.r11, true};
}

datum_initializer_result datum_element_initializer_138f0::initialize(datum_allocation_memory& memory,
    const datum_initializer_call& call) {
    datum_initializer_result result{};

    const std::uint64_t stride = memory.read64(call.array + datum_alloc_stride_offset);

    const bool fill = stride > 0x20u || (call.element & 3u) != 0u || (stride & 3u) != 0u || (stride >> 2u) != 0u;
    if (fill) {
        fill_.fill_at_78932a(call.element, 0u, stride);

    } else {
        result.rdx = call.element;
        result.r8 = 0u;
        result.r9 = call.r9; result.r10 = call.r10; result.r11 = call.r11;
    }

    const std::uint16_t counter = memory.read16(call.counter_address);
    std::uint32_t eax = counter;
    if (counter == 0xffffu) eax = 0xffff8000u;
    const std::uint16_t salt = static_cast<std::uint16_t>(eax);
    memory.write16(call.element, salt);
    const std::uint16_t next = static_cast<std::uint16_t>(salt + 1u);
    memory.write16(call.counter_address, next);
    result.rax = (eax & 0xffff0000u) | next;
    result.rcx = 0xffffffffULL;
    return result;
}
}
