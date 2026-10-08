#include "relative_storage_allocation.hpp"

namespace hum::reconstruction::reach {
namespace {
std::int32_t sign16(std::uint16_t value) { return static_cast<std::int16_t>(value); }
std::uint64_t sign64(std::int32_t value) { return static_cast<std::uint64_t>(static_cast<std::int64_t>(value)); }

void write_absent(relative_storage_dependencies& d, object_storage_address descriptor) {
    d.write16(descriptor + 2, 0xffffu);
    d.write16(descriptor, 0);
}
}

bool allocate_relative_storage(relative_storage_dependencies& d, const relative_storage_request& r) {
    const std::uint64_t entry_offset = static_cast<std::uint64_t>(r.object_handle & 0xffffu) * object_entry_stride;
    const object_storage_address first_table = d.object_entry_table();
    const object_storage_address entry = first_table + entry_offset;
    const std::uint64_t descriptor_delta = sign64(sign16(r.descriptor_offset));

    if (r.size == 0) {
        write_absent(d, d.read64(entry + object_entry_payload_offset) + descriptor_delta);
        return true;
    }

    const std::int32_t old_size = sign16(d.read16(entry + object_entry_size_word_offset));
    const std::uint32_t old_offset = d.read32(entry + object_entry_pool_offset_offset);
    const std::uint32_t slack = (std::uint32_t{1} << (r.alignment_exponent & 31u)) - 1u;
    const std::uint32_t added = static_cast<std::uint32_t>(sign16(r.size)) + slack;
    const std::uint32_t total = static_cast<std::uint32_t>(old_size) + added;

    const std::uint32_t new_offset = d.pool_resize(d.object_pool(), old_offset, sign64(static_cast<std::int32_t>(total)));
    d.write32(entry + object_entry_pool_offset_offset, new_offset);

    if (new_offset == 0) {

        const object_storage_address table = d.object_entry_table();
        write_absent(d, d.read64(table + entry_offset + object_entry_payload_offset) + descriptor_delta);
        return false;
    }

    const std::int32_t old_now = sign16(d.read16(entry + object_entry_size_word_offset));
    d.write64(entry + object_entry_payload_offset, static_cast<std::uint64_t>(new_offset) + d.object_pool());
    d.write16(entry + object_entry_size_word_offset,
              static_cast<std::uint16_t>(added + static_cast<std::uint32_t>(old_now)));

    const object_storage_address table = d.object_entry_table();
    const std::uint16_t keep = static_cast<std::uint16_t>(~slack);
    const std::uint16_t aligned = static_cast<std::uint16_t>(
        static_cast<std::uint16_t>(static_cast<std::uint32_t>(old_now) + slack) & keep);
    const object_storage_address descriptor =
        d.read64(table + entry_offset + object_entry_payload_offset) + descriptor_delta;
    d.write16(descriptor + 2, aligned);
    d.write16(descriptor, r.size);

    d.fill(sign64(old_now) + d.read64(entry + object_entry_payload_offset), 0, sign64(static_cast<std::int32_t>(added)));
    return true;
}
}
