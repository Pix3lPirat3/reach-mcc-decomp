#include "lookup_6cfd0.hpp"

namespace recon515 {
namespace {
std::int64_t signed32(std::uint64_t value) {
    const auto word = static_cast<std::uint32_t>(value);
    return word <= 0x7fffffffu ? static_cast<std::int64_t>(word) :
        static_cast<std::int64_t>(word) - 0x100000000ll;
}
}
Result body_6cfd0(Memory& memory, std::uint64_t module, Entry entry, Mutant mutant) {
    memory.write(entry.rsp + 8u, 8, entry.rbx);
    memory.write(entry.rsp + 0x10u, 8, entry.rdi);
    auto root_or_segment = memory.read(module + 0xc1a230u, 8);
    const auto first_output = entry.r8;
    std::uint32_t index = 0;
    const auto count = signed32(memory.read(root_or_segment + 0x228u, 4));
    auto cursor = static_cast<std::uint64_t>(count);
    auto tag_or_entry_rcx = entry.rcx;
    auto remaining = entry.rdx;
    bool found = false;
    if (count > 0) {
        const auto tag = static_cast<std::uint32_t>(memory.read(root_or_segment + 0x22cu, 4));
        tag_or_entry_rcx = tag;
        root_or_segment = memory.read(module + 0x4e39f20u +
            std::uint64_t{tag >> 28u} * 8u, 8);
        const auto address_tag = mutant == Mutant::masked_tag ? tag & 0x0fffffffu : tag;
        cursor = root_or_segment + (std::uint64_t{address_tag} + 2u) * 4u;
        for (std::int64_t visited = 0; visited < count; ++visited) {
            const auto compared = static_cast<std::uint32_t>(memory.read(cursor, 4));
            const auto less = mutant == Mutant::unsigned_compare ?
                static_cast<std::uint32_t>(remaining) < compared :
                signed32(remaining) < signed32(compared);
            if (less) { found = true; break; }

            const auto subtracted = mutant == Mutant::cached_subtract ? compared :
                static_cast<std::uint32_t>(memory.read(cursor, 4));
            remaining = static_cast<std::uint32_t>(
                static_cast<std::uint32_t>(remaining) - subtracted);
            ++index;
            cursor += mutant == Mutant::stride_four ? 4u : 0x14u;
        }
    }
    if (found) {
        if (mutant == Mutant::reverse_outputs) {
            if (entry.r9 != 0u) memory.write(entry.r9, 4, static_cast<std::uint32_t>(remaining));
            if (first_output != 0u) memory.write(first_output, 4, index);
        } else {
            if (first_output != 0u) memory.write(first_output, 4, index);
            if (entry.r9 != 0u) memory.write(entry.r9, 4, static_cast<std::uint32_t>(remaining));
        }
    } else if (mutant == Mutant::clear_miss) {
        if (first_output != 0u) memory.write(first_output, 4, 0xffffffffu);
        if (entry.r9 != 0u) memory.write(entry.r9, 4, 0xffffffffu);
    }
    const auto restored_rbx = memory.read(entry.rsp + 8u, 8);
    const auto restored_rdi = memory.read(entry.rsp + 0x10u, 8);
    return {root_or_segment, tag_or_entry_rcx, remaining, cursor, entry.r9,
        index, first_output, restored_rbx, restored_rdi};
}
}
