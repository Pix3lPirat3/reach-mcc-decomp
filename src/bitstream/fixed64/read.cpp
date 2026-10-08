#include "read.hpp"
#include <bit>
#include <stdexcept>

namespace hum::reconstruction::reach::recon2956 {
namespace {

std::uint64_t byteswap64(std::uint64_t value) {
    std::uint64_t out = 0;
    for (unsigned i = 0; i < 8; ++i) {
        out = (out << 8) | (value & 0xffU);
        value >>= 8;
    }
    return out;
}
}

native_bitstream_reader_continuation read_fixed64(
    native_bitstream_reader_memory& memory, std::uint64_t reader,
    std::uint64_t incoming_rdx, native_bitstream_reader_private_input& home) {

    if (static_cast<std::uint32_t>(incoming_rdx) != 64U)
        throw std::invalid_argument("Outside fixed64 fixture domain");

    const std::uint32_t consumed = memory.read32(reader + 0x30);
    const std::uint32_t available = 64U - consumed;

    const std::uint64_t old_window = memory.read64(reader + 0x28);

    const bool take_slow_path =
        std::bit_cast<std::int32_t>(std::uint32_t{64}) >
        std::bit_cast<std::int32_t>(available);

    std::uint64_t result;
    std::uint64_t rdx_bits;
    std::uint64_t window_to_store;
    std::uint32_t next;

    if (!take_slow_path) {

        memory.write32(reader + 0x24, memory.read32(reader + 0x24) + 64U);
        next = consumed + 64U;
        result = old_window;
        rdx_bits = old_window;

        window_to_store = 0;
    } else {

        std::uint64_t cursor = memory.read64(reader + 0x38);
        std::uint64_t refill = 0;
        std::uint32_t fetched = 0;

        if (cursor + 8 <= memory.read64(reader + 8)) {

            const std::uint64_t raw = memory.read64(cursor);
            memory.write64(reader + 0x38, cursor + 8);
            refill = byteswap64(raw);
            fetched = 64;
        } else if (cursor < memory.read64(reader + 8)) {

            do {
                const std::uint8_t byte = memory.read8(cursor);
                fetched += 8;
                refill = (refill << 8) | byte;
                ++cursor;
                memory.write64(reader + 0x38, cursor);
            } while (cursor < memory.read64(reader + 8));
            refill <<= (64U - fetched) & 63U;
        } else {

            fetched = home.empty_refill_caller_home_word();
        }

        memory.write32(reader + 0x20, memory.read32(reader + 0x20) + fetched);
        memory.write32(reader + 0x24, memory.read32(reader + 0x24) + 64U);
        next = (consumed - 64U) + 64U;

        rdx_bits = refill >> ((64U - next) & 63U);
        result = old_window | rdx_bits;

        const std::uint64_t window_candidate = refill << (next & 63U);
        const std::int64_t signed_next = std::bit_cast<std::int32_t>(next);
        const bool keep_window =
            static_cast<std::uint64_t>(signed_next) < 64U;
        window_to_store = keep_window ? window_candidate : 0U;
    }

    memory.write64(reader + 0x28, window_to_store);
    memory.write32(reader + 0x30, next);
    return {result, rdx_bits, 64};
}
}
