#include "simulation_detach_link.hpp"

namespace hum::reconstruction::reach {
void detach_object_link(detach_link_environment& env, std::uint32_t object_handle) {
    detach_link_dependencies& d = env.dependencies;

    const std::uint64_t tls_index = d.read32(env.module_base + detach_rva_tls_index);
    const detach_link_address type_table = env.module_base + detach_rva_type_table;

    const detach_link_address slots = d.read64(env.thread_environment + detach_gs_tls_slots);
    const std::uint64_t index = object_handle & 0xffffu;

    const detach_link_address block = d.read64(slots + tls_index * 8);
    const detach_link_address array = d.read64(block + detach_block_object_array);
    const detach_link_address storage = d.read64(array + detach_array_storage);

    const detach_link_address object = d.read64(storage + index * 3 * 8 + detach_object_element_pointer);

    const std::int64_t type = static_cast<std::int8_t>(d.read8(object + detach_object_type_byte));
    const detach_link_address type_definition = d.read64(type_table + static_cast<std::uint64_t>(type) * 8);

    detach_link_address component = d.read64(type_definition + detach_type_components);
    std::uint16_t counter = 0;

    while (component != 0) {
        const detach_link_address callback = d.read64(component + detach_component_callback);
        if (callback != 0) {

            (void)d.component_callback({callback, object_handle, component});
        }
        counter = static_cast<std::uint16_t>(counter + 1);
        const std::int64_t signed_index = static_cast<std::int16_t>(counter);
        component = d.read64(type_definition + static_cast<std::uint64_t>(signed_index) * 8 + detach_type_components);
    }

    (void)d.read32(object + detach_object_link_offset);
    d.write32(object + detach_object_link_offset, detach_link_none);

    d.write8(object + detach_object_state, 0);

    if (static_cast<std::int16_t>(d.read16(object + detach_object_fill_count)) > 0) {

        const std::int64_t offset = static_cast<std::int16_t>(d.read16(object + detach_object_fill_offset));
        (void)d.imported_fill({object + static_cast<std::uint64_t>(offset), 0u, detach_fill_size});
    }
}
}
