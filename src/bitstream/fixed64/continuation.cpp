#include "continuation.hpp"
#include <bit>
#include <stdexcept>

namespace hum::reconstruction::reach::recon663 {
namespace {
std::uint64_t reverse64(std::uint64_t value) {
    std::uint64_t result = 0;
    for (unsigned i = 0; i < 8; ++i) {
        result = (result << 8) | (value & 255U);
        value >>= 8;
    }
    return result;
}
void add32(native_bitstream_reader_memory& m, std::uint64_t at,
           std::uint32_t value) {
    const auto old = m.read32(at);
    m.write32(at, old + value);
}
}
native_bitstream_reader_continuation read_fixed64(
    native_bitstream_reader_memory& m, std::uint64_t reader,
    std::uint64_t incoming_rdx, native_bitstream_reader_private_input& home) {
    if (static_cast<std::uint32_t>(incoming_rdx) != 64U)
        throw std::invalid_argument("Outside fixed64 fixture domain");
    const auto consumed = m.read32(reader + 0x30);
    const auto old = m.read64(reader + 0x28);
    const auto available = std::uint32_t{64} - consumed;
    std::uint32_t next = consumed;
    std::uint64_t window = 0, result = old, rdx = old;
    if (std::bit_cast<std::int32_t>(available) >= 64) {
        add32(m, reader + 0x24, 64);
        next += 64;

    } else {
        auto cursor = m.read64(reader + 0x38);
        std::uint64_t refill = 0;
        std::uint32_t fetched = 0;
        if (cursor + 8 <= m.read64(reader + 8)) {
            const auto raw = m.read64(cursor);
            m.write64(reader + 0x38, cursor + 8);
            refill = reverse64(raw);
            fetched = 64;
        } else if (cursor < m.read64(reader + 8)) {
            do {
                const auto byte = m.read8(cursor);
                fetched += 8;
                refill = (refill << 8) | byte;
                ++cursor;
                m.write64(reader + 0x38, cursor);
            } while (cursor < m.read64(reader + 8));
            refill <<= (64U - fetched) & 63U;
        } else {
            fetched = home.empty_refill_caller_home_word();
        }
        add32(m, reader + 0x20, fetched);

        add32(m, reader + 0x24, 64);
        rdx = refill >> ((64U - next) & 63U);
        result = old | rdx;
        const auto signed_next = std::bit_cast<std::int32_t>(next);
        if (static_cast<std::uint64_t>(static_cast<std::int64_t>(signed_next)) < 64)
            window = refill << (next & 63U);
    }
    m.write64(reader + 0x28, window);
    m.write32(reader + 0x30, next);
    return {result, rdx, 64};
}
}
