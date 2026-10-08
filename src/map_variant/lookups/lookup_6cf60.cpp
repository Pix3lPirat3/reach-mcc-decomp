#include "lookup_6cf60.hpp"
namespace recon453 {
namespace {
std::uint64_t signed_word(std::uint64_t v) {
    const auto w = static_cast<std::uint32_t>(v);
    return (w & 0x80000000u) != 0u ? std::uint64_t{w} | 0xffffffff00000000ull : w;
}
}
Result body_6cf60(Memory& m, Dependency& dependency, std::uint64_t module,
                  Entry entry, Mutant mutant) {
    m.write(entry.rsp + 8u, 8, entry.rcx);

    const auto first_home = entry.rsp + 8u;
    const auto second_home = entry.rsp + 0x18u;
    m.write(first_home, 4, 0xffffffffu);
    m.write(second_home, 4, 0xffffffffu);
    const auto continuation = dependency.call_6cfd0(m,
        {0xffffffffu, entry.rcx, entry.rdx, first_home, second_home, entry.r10, entry.r11});
    const auto first_word = m.read(first_home, 4);
    const auto first = mutant == Mutant::stale_first ? 0xffffffffffffffffull :
        (mutant == Mutant::unsigned_first ? first_word : signed_word(first_word));
    const auto table = module + 0x4e39f20u;
    const auto root = m.read(module + 0xc1a230u, 8);
    const auto first_tag = static_cast<std::uint32_t>(m.read(root + 0x22cu, 4));
    const auto tag_for_address = mutant == Mutant::masked_tag ? first_tag & 0x0fffffffu : first_tag;

    const auto first_index = std::uint64_t{tag_for_address} + first *
        (mutant == Mutant::first_stride_four ? 4u : 5u);
    const auto first_segment = m.read(table + std::uint64_t{first_tag >> 28u} * 8u, 8);
    const auto second_tag = static_cast<std::uint32_t>(m.read(first_segment + first_index * 4u + 0xcu, 4));
    const auto second_word = m.read(second_home, 4);
    const auto second = mutant == Mutant::unsigned_second ? second_word : signed_word(second_word);
    const auto second_index = second * 7u + second_tag;
    const auto nibble = second_tag >> 28u;
    const auto second_segment = m.read(table + std::uint64_t{nibble} * 8u, 8);
    return {second_segment + second_index * 4u, second_index, nibble, table, root,
            continuation.r10, continuation.r11};
}
}
