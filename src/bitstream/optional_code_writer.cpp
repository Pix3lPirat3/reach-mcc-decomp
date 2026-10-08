#include "optional_code_writer.hpp"

#ifndef OPTIONAL523_ENTRY
#define OPTIONAL523_ENTRY write_optional_code523
#endif
#ifndef OPTIONAL523_MUTANT
#define OPTIONAL523_MUTANT 0
#endif

namespace hum::reconstruction::reach {
native_bitstream_writer_continuation OPTIONAL523_ENTRY(
    native_bitstream_writer_memory& memory,native_bitstream_address stream,
    std::uint32_t raw_value) {
    auto occupied = memory.read32(stream + 0x30);
    std::uint64_t rdx = raw_value == 0xffffffffU ? 1U : 0U;
    auto r11 = stream;

    if (occupied >= 64U) {
        const auto next = flush_native_bitstream(memory,stream,rdx,1,r11);
        rdx = next.rdx_bits;
        r11 = next.r11_bits;
    } else {
        const auto requested = memory.read32(stream + 0x24);
        memory.write32(stream + 0x24,requested + 1U);
        memory.write32(stream + 0x30,occupied + 1U);
        const auto window = memory.read64(stream + 0x28);
        memory.write64(stream + 0x28,(window << 1) | rdx);
    }
    if (raw_value == 0xffffffffU) return {rdx,r11};
    occupied = memory.read32(r11 + 0x30);
    const auto free = std::uint32_t{64} - occupied;
    rdx = raw_value;
#if OPTIONAL523_MUTANT == 2

    rdx &= 3U;
#endif
#if OPTIONAL523_MUTANT == 1
    const bool slow = free < 2U;
#else
    const bool slow = (free ^ 0x80000000U) < (2U ^ 0x80000000U);
#endif
    if (slow) {
        return flush_native_bitstream(memory,r11,rdx,2,r11);
    }
    const auto requested = memory.read32(r11 + 0x24);
    memory.write32(r11 + 0x24,requested + 2U);
    memory.write32(r11 + 0x30,occupied + 2U);
    const auto window = memory.read64(r11 + 0x28);
    memory.write64(r11 + 0x28,(window << 2) | rdx);
    return {rdx,r11};
}
}
