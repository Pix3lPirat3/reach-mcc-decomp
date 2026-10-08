#include "reset.hpp"

#include <array>
#include <cstddef>

namespace hum::reconstruction::reach {
namespace {
template<std::size_t N>
std::array<std::uint8_t, N> read(map_variant_reset_dependencies& d,
                               map_reset_address a) {
    std::array<std::uint8_t, N> bytes{};
    d.read_memory(a, bytes);
    return bytes;
}
template<std::size_t N>
void store(map_variant_reset_dependencies& d, map_reset_address a,
           std::uint64_t bits) {
    static_assert(N <= 8);
    std::array<std::uint8_t, N> bytes{};
    for (std::size_t i = 0; i < N; ++i)
        bytes[i] = static_cast<std::uint8_t>(bits >> (8 * i));
    d.write_memory(a, bytes);
}
}

std::uint64_t reset_map_variant_6c080(map_variant_reset_dependencies& d,
    map_reset_address v, std::uint32_t id, map_reset_address module,
    map_reset_address bp) {
    (void)d.fill_at_78932a(bp - 0x50, 0, 0x4c);
    store<8>(d, bp - 0xf, 0);
    store<2>(d, bp - 7, 0);
    store<8>(d, bp - 0x20, 0);
    store<8>(d, bp - 0x18, 0);
    store<1>(d, bp - 0xd, 0);
    store<1>(d, bp - 6, 0xff);
    store<2>(d, bp - 0xc, 0xffff);
    store<1>(d, bp - 9, 8);
    store<2>(d, bp - 0x4e, 0xffff);
    store<4>(d, bp - 0x4c, 0xffffffffu);
    store<2>(d, bp - 0x24, 0xffff);
    store<1>(d, bp - 5, 0);
    store<1>(d, bp - 0x10, 0);
    store<2>(d, bp + 0x38, 0);
    (void)d.fill_at_78932a(v, 0, 0xd9bc);
    store<1>(d, v, 0xff);
    store<1>(d, v + 0x28, 0xff);
    store<4>(d, v + 0x2c, 0xffffffffu);
    store<1>(d, v + 0x30, 0xff);
    store<4>(d, v + 0x2b4, id);
    store<1>(d, v + 0x2e9, 1);
    const auto identifier_source = static_cast<std::uint32_t>(id + 2u) <= 1u
        ? module + 0x985c10 : d.identifier_at_3c5fc(bp - 0x60, id);
    auto xmm0 = read<16>(d, identifier_source);
    auto xmm1 = read<16>(d, bp - 0x40);
    d.write_memory(v + 0x2b8, xmm0);
    xmm0 = read<16>(d, bp - 0x50);
    for (std::uint64_t i = 0; i < 31; ++i)
        store<4>(d, v + 0xd940 + i * 4, 0xffffffffu);
    store<4>(d, v + 0x14f8, 0);
    for (std::uint64_t i = 0; i < 256; ++i)
        store<2>(d, v + 0x12f8 + i * 2, 0xffff);
    const auto tail = read<4>(d, bp - 8);
    store<4>(d, v + 0x12f4, 0);
    d.write_memory(v + 0x14fc, xmm0);
    xmm0 = read<16>(d, bp - 0x30);
    d.write_memory(v + 0x150c, xmm1);
    xmm1 = read<16>(d, bp - 0x20);
    d.write_memory(v + 0x151c, xmm0);
    const auto last_qword = read<8>(d, bp - 0x10);
    d.write_memory(v + 0x152c, xmm1);
    d.write_memory(v + 0x153c, last_qword);
    d.write_memory(v + 0x1544, tail);
    const auto quota_bytes = read<2>(d, bp + 0x38);
    const std::uint16_t quota = static_cast<std::uint16_t>(
        quota_bytes[0] | (static_cast<std::uint16_t>(quota_bytes[1]) << 8));
    for (std::uint64_t i = 0; i < 0x303e; ++i) {
        const auto word = read<4>(d, v + 0x14fc + i * 4);
        d.write_memory(v + 0x1548 + i * 4, word);
    }
    store<2>(d, v + 0xd640, quota);
    store<1>(d, v + 0xd642, 0);
    for (std::uint64_t i = 0; i < 0x2fd; ++i) {
        const auto byte = read<1>(d, v + 0xd640 + i);
        d.write_memory(v + 0xd643 + i, byte);
    }
    store<4>(d, v + 0x2b0, 0x20);
    const auto bounds = read<16>(d, module + 0x98fa10);
    d.write_memory(v + 0x2c8, bounds);
    const auto bounds_tail = read<8>(d, module + 0x98fa20);
    d.write_memory(v + 0x2d8, bounds_tail);
    store<8>(d, v + 0x2e0, 0);
    store<1>(d, v + 0x2e8, 0);
    store<4>(d, v + 0x2ec, 0xffffffffu);
    return (id & 0x80000000u) != 0 ? quota : d.apply_at_70434(v);
}
}
