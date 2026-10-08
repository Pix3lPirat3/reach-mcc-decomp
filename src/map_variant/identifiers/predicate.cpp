#include "predicate.hpp"

namespace hum::reconstruction::reach::identifier_predicate {
result evaluate_d114(dependencies& memory, address input,
    std::uint64_t incoming_rax, std::uint64_t incoming_rdx) {
    if (memory.read32(input) != 0)
        return {(incoming_rax & ~0xffULL) | 1, incoming_rdx, 1};
    if (memory.read16(input + 4) != 0)
        return {(incoming_rax & ~0xffULL) | 1, incoming_rdx, 1};
    if (memory.read16(input + 6) != 0)
        return {(incoming_rax & ~0xffULL) | 1, incoming_rdx, 1};

    const auto byte9 = memory.read8(input + 9);
    auto suffix = static_cast<std::uint64_t>(memory.read8(input + 8));
    suffix = (suffix << 8) | byte9;
    for (std::uint64_t offset = 10; offset < 16; ++offset)
        suffix = (suffix << 8) | memory.read8(input + offset);
    const std::uint64_t nonzero = suffix != 0 ? 1 : 0;
    return {nonzero, suffix, nonzero};
}
}
