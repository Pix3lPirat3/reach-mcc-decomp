#pragma once

#include <cstdint>

namespace hum::reconstruction::reach {
using object_payload_address = std::uint64_t;

constexpr std::uint64_t object_payload_rva_tls_index = 0xc17b18;
constexpr std::uint64_t object_payload_gs_tls_slots = 0x58;
constexpr std::uint64_t object_payload_block_array_header = 0x10;
constexpr std::uint64_t object_payload_block_pool = 0x358;
constexpr std::uint64_t object_payload_header_storage = 0x50;
constexpr std::uint64_t object_payload_element_stride = 24;
constexpr std::uint64_t object_payload_element_pointer = 0x10;

enum class object_payload_register_state : std::uint8_t { preserved, provided, unavailable };

struct object_payload_register_carrier {
    object_payload_register_state state = object_payload_register_state::unavailable;
    std::uint64_t value = 0;
    static object_payload_register_carrier preserved_value() { return {object_payload_register_state::preserved, 0}; }
    static object_payload_register_carrier provided_value(std::uint64_t v) { return {object_payload_register_state::provided, v}; }
    static object_payload_register_carrier unavailable_value() { return {}; }
};

struct object_payload_free_residue {
    object_payload_register_carrier r9;
    object_payload_register_carrier r10;
    object_payload_register_carrier r11;
};

struct object_payload_free_call {
    object_payload_address pool;
    std::uint32_t offset;
    std::uint64_t held_r9;
    std::uint64_t held_r10;
    std::uint64_t held_r11;
};

struct object_payload_release_dependencies {
    virtual ~object_payload_release_dependencies() = default;
    virtual std::uint32_t read32(object_payload_address) = 0;
    virtual std::uint64_t read64(object_payload_address) = 0;
    virtual void write64(object_payload_address, std::uint64_t) = 0;

    virtual object_payload_free_residue free_block_68a424(const object_payload_free_call&) = 0;

    virtual void release_datum_136f0(object_payload_address array, std::uint32_t handle) = 0;
};

struct object_payload_release_environment {
    object_payload_release_dependencies& dependencies;
    object_payload_address module_base;
    object_payload_address thread_environment;
};

enum class object_payload_release_outcome : std::uint8_t {
    completed_without_payload,
    completed_released,
    stopped_before_clear,
    stopped_before_header_reload
};

struct object_payload_release_result {
    object_payload_release_outcome outcome;
    std::uint8_t unavailable_mask;
};

object_payload_release_result release_object_payload(object_payload_release_environment& environment, std::uint32_t handle);
}
