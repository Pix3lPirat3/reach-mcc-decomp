#include "finalize.hpp"
#include <bit>
#include <limits>
#include <stdexcept>

namespace hum::reconstruction::reach {
namespace {
std::uint64_t reverse_bytes(std::uint64_t value) {
    std::uint64_t reversed = 0;
    for (unsigned i = 0; i < 8; ++i) {
        reversed = (reversed << 8) | (value & 0xffU);
        value >>= 8;
    }
    return reversed;
}
}
bitstream_finalize_continuation finalize_bitstream(
    bitstream_finalize_memory& memory, bitstream_finalize_address stream) {
    const auto occupancy = memory.read32(stream + 0x30);
    auto reservoir = memory.read64(stream + 0x28);
    if (occupancy != 64) {
        reservoir <<= (64U - occupancy) & 63U;
        memory.write64(stream + 0x28, reservoir);
    }
    const auto initial_cursor = memory.read64(stream + 0x38);
    if (initial_cursor + 8 <= memory.read64(stream + 8)) {
        memory.write64(initial_cursor, reverse_bytes(reservoir));
        const auto cursor = memory.read64(stream + 0x38);
        memory.write64(stream + 0x38, cursor + 8);
    } else if (initial_cursor < memory.read64(stream + 8)) {
        do {
            const auto cursor = memory.read64(stream + 0x38);
            const auto byte = static_cast<std::uint8_t>(reservoir >> 56);
            reservoir <<= 8;
            memory.write8(cursor, byte);
            const auto stored_cursor = memory.read64(stream + 0x38);
            memory.write64(stream + 0x38, stored_cursor + 1);
            const auto advanced_cursor = memory.read64(stream + 0x38);
            const auto end = memory.read64(stream + 8);
            if (advanced_cursor >= end) break;
        } while (true);
    }
    const auto previous_total = memory.read32(stream + 0x20);
    memory.write32(stream + 0x20, previous_total + occupancy);
    const auto total = memory.read32(stream + 0x20);

    static_cast<void>(memory.read64(stream + 0x28));
    memory.write64(stream + 0x28, 0);
    static_cast<void>(memory.read32(stream + 0x30));
    memory.write32(stream + 0x30, 0);

    const auto byte_count = std::bit_cast<std::int32_t>(total + std::uint32_t{7}) / 8;
    const auto count_bits = static_cast<std::uint32_t>(byte_count);
    memory.write32(stream + 0x10, count_bits);
    const auto divisor = std::bit_cast<std::int32_t>(memory.read32(stream + 0x14));
    if (divisor == 0 || (byte_count == std::numeric_limits<std::int32_t>::min() && divisor == -1))
        throw std::domain_error("unadmitted finalizer IDIV fault");
    const auto quotient = static_cast<std::int64_t>(byte_count) / divisor;
    const auto remainder = static_cast<std::int64_t>(byte_count) % divisor;
    const auto signed_count = static_cast<std::uint64_t>(static_cast<std::int64_t>(byte_count));
    const auto start = memory.read64(stream);
    const auto end = start + signed_count;
    memory.write64(stream + 8, end);
    auto r9 = signed_count;
    if (remainder != 0) {
        const auto rounded = count_bits - static_cast<std::uint32_t>(remainder)
            + memory.read32(stream + 0x14);
        memory.write32(stream + 0x10, rounded);
        r9 = rounded;
    }
    memory.write32(stream + 0x18, 2);
    return {static_cast<std::uint32_t>(quotient), end,
        static_cast<std::uint32_t>(remainder), stream, r9, occupancy, initial_cursor};
}
}
