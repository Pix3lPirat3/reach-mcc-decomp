#include "qword_reader.hpp"

namespace hum::reconstruction::reach {
namespace {
std::uint64_t sign_extend(std::uint32_t x) {
    return (x & 0x80000000U) ? (0xffffffff00000000ULL | x) : x;
}
std::uint64_t reverse64(std::uint64_t x) {
    std::uint64_t out = 0;
    for (unsigned i = 0; i < 8; ++i) {
        out = (out << 8) | (x & 255U);
        x >>= 8;
    }
    return out;
}
void add32(native_bitstream_reader_memory& m, std::uint64_t at,
           std::uint32_t increment) {
    const auto old = m.read32(at);
    m.write32(at, old + increment);
}
}
native_bitstream_reader_continuation read_native_bitstream_qword(
    native_bitstream_reader_memory& m, native_bitstream_reader_address reader,
    std::uint64_t incoming_rdx, native_bitstream_reader_private_input& home) {
    const auto width = static_cast<std::uint32_t>(incoming_rdx);
    const auto r11 = sign_extend(width);
    const auto consumed = m.read32(reader + 0x30);
    const auto old_window = m.read64(reader + 0x28);
    const std::uint32_t available = 64U - consumed;
    std::uint32_t next;
    std::uint64_t result, rdx, window;

    if ((width ^ 0x80000000U) <= (available ^ 0x80000000U)) {
        add32(m, reader + 0x24, width);
        next = consumed + width;
        result = old_window >> ((64U - width) & 63U);
        rdx = old_window << (width & 63U);
        window = r11 < 64U ? rdx : 0;
    } else {
        auto cursor = m.read64(reader + 0x38);
        const auto next_cursor = cursor + 8U;
        std::uint64_t refill = 0;
        std::uint32_t fetched;
        if (next_cursor <= m.read64(reader + 8)) {
            const auto raw = m.read64(cursor);
            m.write64(reader + 0x38, next_cursor);
            refill = reverse64(raw);
            fetched = 64;
        } else if (cursor < m.read64(reader + 8)) {
            fetched = 0;
            do {
                const auto byte = m.read8(cursor);
                fetched += 8U;
                refill = (refill << 8) | byte;
                ++cursor;
                m.write64(reader + 0x38, cursor);
            } while (cursor < m.read64(reader + 8));
            refill <<= (64U - fetched) & 63U;
        } else {
            fetched = home.empty_refill_caller_home_word();
        }
        add32(m, reader + 0x20, fetched);
        next = consumed - 64U;
        add32(m, reader + 0x24, width);
        next += width;
        rdx = refill >> ((64U - next) & 63U);
        result = (old_window >> ((64U - width) & 63U)) | rdx;
        window = sign_extend(next) < 64U ? (refill << (next & 63U)) : 0;
    }
    m.write64(reader + 0x28, window);
    m.write32(reader + 0x30, next);
    return {result, rdx, r11};
}
}
