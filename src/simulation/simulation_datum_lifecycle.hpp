#pragma once
#include <cstdint>

#include "../common/datum_lookup.hpp"

namespace hum::reconstruction::reach {

struct simulation_datum_memory : datum_lookup_memory {
    virtual std::uint8_t read8(datum_lookup_address) = 0;
    virtual void write8(datum_lookup_address, std::uint8_t) = 0;
    virtual void write32(datum_lookup_address, std::uint32_t) = 0;
};

struct simulation_datum_dependencies {
    virtual ~simulation_datum_dependencies() = default;

    virtual std::uint32_t datum_allocate(datum_lookup_address array) = 0;

    virtual void datum_release(datum_lookup_address array, std::uint32_t handle_bits) = 0;

    virtual bool context_busy() = 0;

    virtual void registry_unlink(std::uint32_t entity_id) = 0;

    virtual void object_link_detach(std::uint32_t object_handle) = 0;

    virtual void post_detach(std::uint32_t selector, std::uint32_t object_handle) = 0;
};

struct simulation_datum_environment {
    simulation_datum_memory& memory;
    simulation_datum_dependencies& calls;

    datum_lookup_address thread_block;
};

inline constexpr std::uint64_t sim_tls_object_array_offset = 0x10;
inline constexpr std::uint64_t sim_tls_context_offset = 0x48;
inline constexpr std::uint64_t sim_tls_local_datum_array_offset = 0xf0;
inline constexpr std::uint8_t sim_context_gate_value = 5;
inline constexpr std::uint64_t sim_context_gate_offset = 0x11;

inline constexpr std::uint64_t sim_array_storage_offset = 0x50;

inline constexpr std::uint64_t sim_local_record_step = 12;
inline constexpr std::uint64_t sim_local_record_byte2_offset = 2;
inline constexpr std::uint64_t sim_local_record_entity_id_offset = 4;
inline constexpr std::uint64_t sim_local_record_object_offset = 8;

inline constexpr std::uint64_t sim_object_element_step = 24;
inline constexpr std::uint64_t sim_object_element_pointer_offset = 0x10;
inline constexpr std::uint64_t sim_object_local_link_offset = 0xfc;
inline constexpr std::uint32_t sim_handle_none = 0xffffffffU;
inline constexpr std::uint32_t sim_post_detach_selector = 0x1000;

std::uint32_t allocate_local_datum(simulation_datum_environment&);

void release_local_datum(simulation_datum_environment&, std::uint32_t handle_bits);

bool local_datum_exists(simulation_datum_environment&, std::uint32_t handle_bits);

void release_object_mapping(simulation_datum_environment&, std::uint32_t object_handle);

}
