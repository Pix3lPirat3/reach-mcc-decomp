#include "simulation_datum_lifecycle.hpp"

namespace hum::reconstruction::reach {
namespace {
std::uint64_t low16_index(std::uint32_t handle_bits) { return handle_bits & 0xffffU; }
}

std::uint32_t allocate_local_datum(simulation_datum_environment& env) {
    auto& m = env.memory;

    datum_lookup_address array = m.read64(env.thread_block + sim_tls_local_datum_array_offset);

    const std::uint32_t handle = env.calls.datum_allocate(array);

    if (handle == sim_handle_none) return handle;

    array = m.read64(env.thread_block + sim_tls_local_datum_array_offset);

    const datum_lookup_address record =
        m.read64(array + sim_array_storage_offset) + low16_index(handle) * sim_local_record_step;

    m.write32(record + sim_local_record_object_offset, sim_handle_none);
    m.write32(record + sim_local_record_entity_id_offset, sim_handle_none);
    m.write8(record + sim_local_record_byte2_offset, 0);
    return handle;
}

void release_local_datum(simulation_datum_environment& env, std::uint32_t handle_bits) {

    const datum_lookup_address array =
        env.memory.read64(env.thread_block + sim_tls_local_datum_array_offset);
    env.calls.datum_release(array, handle_bits);
}

bool local_datum_exists(simulation_datum_environment& env, std::uint32_t handle_bits) {

    if (handle_bits == sim_handle_none) return false;
    const datum_lookup_address array =
        env.memory.read64(env.thread_block + sim_tls_local_datum_array_offset);

    return lookup_datum_handle(env.memory, array, handle_bits) != 0;
}

void release_object_mapping(simulation_datum_environment& env, std::uint32_t object_handle) {
    auto& m = env.memory;

    const datum_lookup_address context = m.read64(env.thread_block + sim_tls_context_offset);
    if (m.read8(context + sim_context_gate_offset) != sim_context_gate_value) return;

    const datum_lookup_address object_array = m.read64(env.thread_block + sim_tls_object_array_offset);
    const datum_lookup_address object = m.read64(m.read64(object_array + sim_array_storage_offset) +
        low16_index(object_handle) * sim_object_element_step + sim_object_element_pointer_offset);

    std::uint32_t local = m.read32(object + sim_object_local_link_offset);
    if (local == sim_handle_none) return;

    if (!env.calls.context_busy()) {

        const datum_lookup_address local_array = m.read64(env.thread_block + sim_tls_local_datum_array_offset);
        const std::uint32_t entity_id = m.read32(m.read64(local_array + sim_array_storage_offset) +
            low16_index(local) * sim_local_record_step + sim_local_record_entity_id_offset);
        if (entity_id != sim_handle_none) {
            env.calls.registry_unlink(entity_id);
            local = m.read32(object + sim_object_local_link_offset);
        }
    }
    release_local_datum(env, local);

    env.calls.object_link_detach(object_handle);
    env.calls.post_detach(sim_post_detach_selector, object_handle);
}
}
