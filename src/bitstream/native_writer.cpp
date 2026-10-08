#include "native_writer.hpp"

namespace hum::reconstruction::reach {
namespace {
std::uint64_t reverse64(std::uint64_t value) noexcept {
    value = ((value & 0x00ff00ff00ff00ffULL) << 8)
        | ((value >> 8) & 0x00ff00ff00ff00ffULL);
    value = ((value & 0x0000ffff0000ffffULL) << 16)
        | ((value >> 16) & 0x0000ffff0000ffffULL);
    return (value << 32) | (value >> 32);
}
std::uint32_t reverse32(std::uint32_t value) noexcept {
    return ((value & 0x000000ffU) << 24) | ((value & 0x0000ff00U) << 8)
        | ((value & 0x00ff0000U) >> 8) | (value >> 24);
}
std::uint16_t reverse16(std::uint16_t value) noexcept {
    return static_cast<std::uint16_t>((std::uint32_t{value} << 8) | (value >> 8));
}
bool signed_less32(std::uint32_t left,std::uint32_t right) noexcept {
    return (left ^ 0x80000000U) < (right ^ 0x80000000U);
}
void add_requested(native_bitstream_writer_memory& memory,
                   native_bitstream_address stream,std::uint32_t width) {
    const auto previous = memory.read32(stream + 0x24);
    memory.write32(stream + 0x24,previous + width);
}

std::uint64_t append_field(native_bitstream_writer_memory& memory,
    native_bitstream_address stream,std::uint32_t& occupied,
    std::uint64_t value,std::uint32_t width) {
    if (signed_less32(std::uint32_t{64} - occupied,width)) {
        const auto result = flush_native_bitstream(memory,stream,value,width,stream);
        occupied = memory.read32(stream + 0x30);
        return result.rdx_bits;
    }
    const auto window = memory.read64(stream + 0x28);
    occupied += width;
    add_requested(memory,stream,width);
    memory.write32(stream + 0x30,occupied);
    memory.write64(stream + 0x28,(window << width) | value);
    return value;
}
}

native_bitstream_writer_continuation flush_native_bitstream(
    native_bitstream_writer_memory& memory,native_bitstream_address stream,
    std::uint64_t value_bits,std::uint32_t width,std::uint64_t incoming_r11) {
    add_requested(memory,stream,width);
    const auto free = std::uint32_t{64} - memory.read32(stream + 0x30);
    std::uint64_t emitted = memory.read64(stream + 0x28);
    const auto spill = width - free;
    memory.write32(stream + 0x30,spill);
    memory.write64(stream + 0x28,value_bits);
    std::uint64_t returned_rdx = value_bits;
    if (spill < 64U) {
        returned_rdx >>= spill & 63U;
        emitted = (emitted << (free & 63U)) | returned_rdx;
    }
    const auto cursor = memory.read64(stream + 0x38);
    if (cursor + std::uint64_t{8} <= memory.read64(stream + 8)) {
        returned_rdx = reverse64(emitted);
        memory.write64(cursor,returned_rdx);

        const auto changed_cursor = memory.read64(stream + 0x38);
        memory.write64(stream + 0x38,changed_cursor + 8);
    } else if (cursor < memory.read64(stream + 8)) {
        std::uint64_t next;
        do {
            const auto target = memory.read64(stream + 0x38);
            const auto byte = static_cast<std::uint8_t>(emitted >> 56);
            emitted <<= 8;
            memory.write8(target,byte);
            const auto changed_cursor = memory.read64(stream + 0x38);
            memory.write64(stream + 0x38,changed_cursor + 1);
            next = memory.read64(stream + 0x38);
        } while (next < memory.read64(stream + 8));
    }
    const auto emitted_bits = memory.read32(stream + 0x20);
    memory.write32(stream + 0x20,emitted_bits + 64);
    return {returned_rdx,incoming_r11};
}

native_bitstream_writer_continuation write_native_bitstream_fields128(
    native_bitstream_writer_memory& memory,native_bitstream_address stream,
    native_bitstream_address source,std::uint64_t                           ) {
    const auto field64 = reverse64(memory.read64(source + 8));
    const auto first16 = reverse16(memory.read16(source + 4));
    const auto second16 = reverse16(memory.read16(source + 6));
    const auto field32 = reverse32(memory.read32(source));
    auto occupied = memory.read32(stream + 0x30);
    auto returned_rdx = append_field(memory,stream,occupied,field32,32);
    returned_rdx = append_field(memory,stream,occupied,first16,16);
    returned_rdx = append_field(memory,stream,occupied,second16,16);
    if (!signed_less32(std::uint32_t{64} - occupied,64)) {
        add_requested(memory,stream,64);
        memory.write32(stream + 0x30,occupied + 64);
        memory.write64(stream + 0x28,field64);
    } else {
        returned_rdx = flush_native_bitstream(memory,stream,field64,64,stream).rdx_bits;
    }
    return {returned_rdx,stream};
}
}
