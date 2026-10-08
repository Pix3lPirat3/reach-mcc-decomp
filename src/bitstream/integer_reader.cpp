#include "integer_reader_detail.hpp"
#include <bit>
#include <optional>

namespace hum::reconstruction::reach {
namespace {
enum class profile { integer_dd10c, guid_fixed_dd274 };
std::uint64_t reverse64(std::uint64_t bits) {
    std::uint64_t result = 0;
    for (unsigned i = 0; i < 8; ++i) { result = (result << 8) | (bits & 0xffU); bits >>= 8; }
    return result;
}
std::uint64_t left(std::uint64_t bits, std::uint32_t count) { return bits << (count & 63U); }
std::uint64_t right(std::uint64_t bits, std::uint32_t count) { return bits >> (count & 63U); }
void add32(native_bitstream_reader_memory& d, std::uint64_t address, std::uint32_t increment) {
    const auto old = d.read32(address);
    d.write32(address, old + increment);
}
std::uint64_t sx32(std::uint32_t bits) {
    return (bits & 0x80000000U) ? (0xffffffff00000000ULL | bits) : bits;
}
struct leaf_result {
    std::uint64_t value,rdx,rcx,r8,r10;

    std::optional<std::uint64_t> r9;
};

leaf_result read_leaf(native_bitstream_reader_memory& d, std::uint64_t reader,
    std::uint64_t incoming_rdx, native_bitstream_reader_private_input& home, profile selected,
    std::optional<std::uint64_t> incoming_r9) {
    const auto width = static_cast<std::uint32_t>(incoming_rdx);
    const auto consumed = d.read32(reader + 0x30U);
    const auto old = d.read64(reader + 0x28U);
    const auto available = 64U - consumed;
    std::uint32_t next_consumed = 0;
    std::uint64_t next_window = 0, result = 0, rdx = incoming_rdx;
    std::uint64_t rcx = static_cast<std::uint8_t>(64U-width),r8 = consumed;
    auto r9 = incoming_r9;
    if (std::bit_cast<std::int32_t>(width) <= std::bit_cast<std::int32_t>(available)) {
        add32(d, reader + 0x24U, width);
        next_consumed = consumed + width;
        result = right(old, 64U - width);
        next_window = selected == profile::guid_fixed_dd274 ? 0 : left(old, width);
    } else {
        auto cursor = d.read64(reader + 0x38U);
        const auto next_cursor = cursor + 8U;
        std::uint64_t refill = 0;
        std::uint32_t fetched = 0;
        if (next_cursor <= d.read64(reader + 8U)) {
            const auto raw = d.read64(cursor);
            d.write64(reader + 0x38U, next_cursor);
            refill = reverse64(raw);
            fetched = 64;
        } else if (cursor < d.read64(reader + 8U)) {
            do {
                const auto byte = d.read8(cursor);
                fetched += 8U;
                refill = (refill << 8) | byte;
                ++cursor;
                d.write64(reader + 0x38U, cursor);
            } while (cursor < d.read64(reader + 8U));
            refill = left(refill, 64U - fetched);
        } else {
            fetched = home.empty_refill_caller_home_word();
        }
        add32(d, reader + 0x20U, fetched);
        next_consumed = consumed - 64U;
        add32(d, reader + 0x24U, width);
        next_consumed += width;

        rdx = left(refill, next_consumed);
        if (next_consumed < 64U) { next_window = rdx; }
        result = right(old, 64U - width) | right(refill, 64U - next_consumed);
        rcx = static_cast<std::uint8_t>(64U-next_consumed);
        r8 = sx32(next_consumed);
        r9 = right(refill,64U-next_consumed);
    }
    d.write64(reader + 0x28U, next_window);
    d.write32(reader + 0x30U, next_consumed);
    return {result,rdx,rcx,r8,reader,r9};
}
}
native_bitstream_reader_continuation read_native_bitstream_integer(
    native_bitstream_reader_memory& d, native_bitstream_reader_address reader,
    std::uint64_t incoming_rdx, native_bitstream_reader_private_input& home) {
    const auto result = read_leaf(d, reader, incoming_rdx, home, profile::integer_dd10c,std::nullopt);
    return {static_cast<std::uint32_t>(result.value), result.rdx, result.value};
}
namespace reader_revision324_detail {
std::uint64_t read_guid_fixed64(native_bitstream_reader_memory& d,
    native_bitstream_reader_address reader, native_bitstream_reader_private_input& home) {
    return read_leaf(d, reader, 64U, home, profile::guid_fixed_dd274,std::nullopt).value;
}
}

native_bitstream_reader_context read_native_bitstream_integer_context(
    native_bitstream_reader_memory& d,native_bitstream_reader_context incoming,
    native_bitstream_reader_private_input& home) {
    const auto result=read_leaf(d,incoming.rcx_bits,incoming.rdx_bits,home,
        profile::integer_dd10c,incoming.r9_bits);
    incoming.rax_bits=static_cast<std::uint32_t>(result.value);
    incoming.rcx_bits=result.rcx;incoming.rdx_bits=result.rdx;
    incoming.r8_bits=result.r8;incoming.r9_bits=*result.r9;
    incoming.r10_bits=result.r10;incoming.r11_bits=result.value;
    return incoming;
}
}
