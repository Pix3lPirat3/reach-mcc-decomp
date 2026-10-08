#include "object_payload_release.hpp"

namespace hum::reconstruction::reach {
namespace {

bool resolve_carrier(const object_payload_register_carrier& carrier, std::uint64_t held, std::uint64_t& out) {
    switch (carrier.state) {
        case object_payload_register_state::preserved: out = held; return true;
        case object_payload_register_state::provided: out = carrier.value; return true;
        default: return false;
    }
}
}

object_payload_release_result release_object_payload(object_payload_release_environment& env, std::uint32_t handle) {
    object_payload_release_dependencies& d = env.dependencies;

    const std::uint64_t tls_index = d.read32(env.module_base + object_payload_rva_tls_index);
    const object_payload_address slots = d.read64(env.thread_environment + object_payload_gs_tls_slots);

    const object_payload_address block = d.read64(slots + tls_index * 8);
    object_payload_address header = d.read64(block + object_payload_block_array_header);

    const std::uint64_t index_times_3 = static_cast<std::uint64_t>(handle & 0xffffu) * 3u;
    const object_payload_address storage = d.read64(header + object_payload_header_storage);

    object_payload_address element_field = storage + index_times_3 * 8 + object_payload_element_pointer;
    const std::uint64_t payload = d.read64(element_field);
    bool released = false;
    std::uint8_t mask = 0;
    if (payload != 0) {

        const std::uint32_t payload_low = d.read32(element_field);

        const object_payload_address pool = d.read64(block + object_payload_block_pool);
        const std::uint32_t offset = payload_low - static_cast<std::uint32_t>(pool);

        const object_payload_free_residue residue = d.free_block_68a424({pool, offset, block, index_times_3, storage});
        mask = static_cast<std::uint8_t>((residue.r9.state == object_payload_register_state::unavailable ? 1u : 0u) |
                                         (residue.r10.state == object_payload_register_state::unavailable ? 2u : 0u) |
                                         (residue.r11.state == object_payload_register_state::unavailable ? 4u : 0u));
        std::uint64_t r9 = 0, r10 = 0, r11 = 0;
        const bool have_r10 = resolve_carrier(residue.r10, index_times_3, r10);
        const bool have_r11 = resolve_carrier(residue.r11, storage, r11);

        if (!have_r10 || !have_r11) return {object_payload_release_outcome::stopped_before_clear, mask};
        element_field = r11 + r10 * 8 + object_payload_element_pointer;
        (void)d.read64(element_field);
        d.write64(element_field, 0);

        if (!resolve_carrier(residue.r9, block, r9)) return {object_payload_release_outcome::stopped_before_header_reload, mask};
        header = d.read64(r9 + object_payload_block_array_header);
        released = true;
    }

    d.release_datum_136f0(header, handle);
    return {released ? object_payload_release_outcome::completed_released : object_payload_release_outcome::completed_without_payload, 0};
}
}
