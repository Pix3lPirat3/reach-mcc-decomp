#pragma once

#include <cstdint>

namespace hum::reconstruction::reach {
using detach_link_address = std::uint64_t;

constexpr std::uint64_t detach_rva_tls_index = 0xc17b18;
constexpr std::uint64_t detach_rva_type_table = 0xa52540;

constexpr std::uint64_t detach_gs_tls_slots = 0x58;
constexpr std::uint64_t detach_block_object_array = 0x10;
constexpr std::uint64_t detach_array_storage = 0x50;
constexpr std::uint64_t detach_object_element_step = 24;
constexpr std::uint64_t detach_object_element_pointer = 0x10;
constexpr std::uint64_t detach_object_type_byte = 0x8e;
constexpr std::uint64_t detach_object_link_offset = 0xfc;
constexpr std::uint64_t detach_object_state = 0x100;
constexpr std::uint64_t detach_object_fill_count = 0x194;
constexpr std::uint64_t detach_object_fill_offset = 0x196;
constexpr std::uint64_t detach_type_components = 0x168;
constexpr std::uint64_t detach_component_callback = 0xb8;
constexpr std::uint64_t detach_fill_size = 0x64;
constexpr std::uint32_t detach_link_none = 0xffffffffu;

struct detach_component_callback_call {
    detach_link_address callback;
    std::uint32_t object_handle;
    detach_link_address component;
};

struct detach_imported_fill_call {
    detach_link_address destination;
    std::uint32_t value;
    std::uint64_t count;
};

struct detach_link_dependencies {
    virtual ~detach_link_dependencies() = default;
    virtual std::uint8_t read8(detach_link_address) = 0;
    virtual std::uint16_t read16(detach_link_address) = 0;
    virtual std::uint32_t read32(detach_link_address) = 0;
    virtual std::uint64_t read64(detach_link_address) = 0;
    virtual void write8(detach_link_address, std::uint8_t) = 0;
    virtual void write32(detach_link_address, std::uint32_t) = 0;

    virtual std::uint64_t component_callback(const detach_component_callback_call&) = 0;

    virtual std::uint64_t imported_fill(const detach_imported_fill_call&) = 0;
};

struct detach_link_environment {
    detach_link_dependencies& dependencies;
    detach_link_address module_base;
    detach_link_address thread_environment;
};

void detach_object_link(detach_link_environment& environment, std::uint32_t object_handle);
}
