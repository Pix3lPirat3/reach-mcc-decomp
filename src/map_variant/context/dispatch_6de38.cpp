#include "dispatch_6de38.hpp"

namespace hum::reach::recon390 {
void body_6de38(Registers& r, const Dependencies& d, std::uint64_t module_base) {
    const auto variant = r.rcx;
    const auto index_bits = static_cast<std::uint32_t>(r.rdx);

    const std::uint64_t index = (index_bits & 0x80000000u)
        ? (0xffffffff00000000ull | index_bits) : index_bits;
    r.r8 = static_cast<std::uint32_t>(d.read(d.context, module_base + tls_index_rva, 4));
    r.rax = d.read_gs58(d.context);
    r.rcx = 0x48;
    r.rax = d.read(d.context, r.rax + r.r8 * 8, 8);
    r.r8 = d.read(d.context, r.rax + r.rcx, 8);
    if (static_cast<std::uint8_t>(d.read(d.context, r.r8 + 0x11, 1)) == 4) return;

    r.rdx = index_bits;
    const auto indexed_variant = variant + index * 2;
    d.call(d.context, 0x6cf60, 0x6de77, r);
    r.r8 &= ~std::uint64_t{0xff};
    r.r9 = 0x28b;
    auto cursor = variant + 0x14fe;
    do {
        const auto word = static_cast<std::uint16_t>(d.read(d.context, cursor, 2));
        r.rdx = (word & 0x8000u) ? (0xffff0000u | word) : word;
        r.rax = static_cast<std::uint32_t>(r.r8 + 1);
        r.rcx = static_cast<std::uint8_t>(r.rax);
        cursor += 0x4c;
        r.rax = static_cast<std::uint8_t>(r.r8);
        if (static_cast<std::uint32_t>(r.rdx) != index_bits) r.rcx = r.rax;
        r.r8 = (r.r8 & ~std::uint64_t{0xff}) | static_cast<std::uint8_t>(r.rcx);
        --r.r9;
    } while (r.r9 != 0);
    const auto previous = static_cast<std::uint8_t>(
        d.read(d.context, indexed_variant + index + 0xd642, 1));
    r.rax = (r.rax & ~std::uint64_t{0xff}) | previous;
    if (previous != static_cast<std::uint8_t>(r.rcx)) {
        r.rdx = static_cast<std::uint32_t>(r.rcx);
        r.rcx = index_bits;
        r.rax = static_cast<std::uint8_t>(r.rax);
        r.rdx = static_cast<std::uint32_t>(r.rdx) - static_cast<std::uint32_t>(r.rax);
        d.call(d.context, 0x760b4, 0x6dec1, r);
    }
    r.rdx = 4;
    r.rcx = index_bits;
    d.call(d.context, 0x3a6054, 0x6decd, r);
}
}
