#include "fields.hpp"

namespace hum::reconstruction::reach::recon2904 {
namespace {
std::uint64_t wrap_offset(std::int64_t displacement) {
    return static_cast<std::uint64_t>(displacement);
}
}

metadata_children_continuation write_byte_string_dc574(metadata_children_memory& memory,
    metadata_children_imports& imports, address reader, address destination,
    std::int32_t length, native_bitstream_reader_private_input& home,
    std::uint64_t entry_rdx_bits) {
    std::int32_t count = 0;
    std::uint64_t last_rax = 0, last_rdx = entry_rdx_bits;
    if (length > 0) {
        for (std::int32_t index = 0; index < length; ++index) {
            const auto step = read_native_bitstream_integer(memory, reader, 8U, home);
            const auto byte = static_cast<std::uint8_t>(step.rax_bits);
            memory.write8(destination + wrap_offset(index), byte);
            last_rax = step.rax_bits;
            last_rdx = step.rdx_bits;
            if (byte == 0) { count = index; goto after_loop; }
            count = index + 1;
        }
    }
after_loop:
    if (count >= length) {

        memory.write8(destination + wrap_offset(static_cast<std::int64_t>(length) - 1), 0);
        memory.write8(reader + 0x1c, 1);
    } else {
        const std::int32_t remaining = length - count;
        if (remaining != 0) {
            const auto fill = imports.call_memset_78932a(
                destination + wrap_offset(count), 0, static_cast<std::uint64_t>(remaining));
            last_rax = fill.rax_bits;
            last_rdx = fill.rdx_bits;
        }
    }
    return {last_rax, last_rdx};
}

metadata_children_continuation write_utf16_string_dc5fc(metadata_children_memory& memory,
    metadata_children_imports& imports, address reader, address destination,
    std::int32_t length, native_bitstream_reader_private_input& home,
    std::uint64_t entry_rdx_bits) {
    std::int32_t count = 0;
    std::uint64_t last_rax = 0, last_rdx = entry_rdx_bits;
    if (length > 0) {
        for (std::int32_t index = 0; index < length; ++index) {
            const auto step = read_native_bitstream_integer(memory, reader, 0x10U, home);
            const auto unit = static_cast<std::uint16_t>(step.rax_bits);
            memory.write16(destination + wrap_offset(index) * 2U, unit);
            last_rax = step.rax_bits;
            last_rdx = step.rdx_bits;
            if (unit == 0) { count = index; goto after_loop; }
            count = index + 1;
        }
    }
after_loop:
    if (count >= length) {

        memory.write16(destination + wrap_offset(static_cast<std::int64_t>(length) * 2 - 2), 0);
        memory.write8(reader + 0x1c, 1);
    } else {
        const std::int32_t remaining = length - count;
        if (remaining != 0) {
            const auto fill = imports.call_memset_78932a(
                destination + wrap_offset(count) * 2U, 0,
                static_cast<std::uint64_t>(remaining) * 2U);
            last_rax = fill.rax_bits;
            last_rdx = fill.rdx_bits;
        }
    }
    return {last_rax, last_rdx};
}

metadata_children_continuation write_metadata_object_children_103968(
    metadata_children_memory& memory, metadata_children_imports& imports,
    address reader, address destination, native_bitstream_reader_private_input& home) {
    const auto first = imports.call_dd274(reader);
    memory.write64(destination, first.rax_bits);
    const auto second = imports.call_dd274(reader);
    memory.write64(destination + 8, second.rax_bits);
    write_byte_string_dc574(memory, imports, reader, destination + 0x10, 16,
        home, second.rdx_bits);
    const auto last = read_native_bitstream_integer(memory, reader, 1U, home);
    memory.write8(destination + 0x20, static_cast<std::uint8_t>(last.rax_bits));
    return {last.rax_bits, last.rdx_bits};
}
}
