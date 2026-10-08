#pragma once

#include <cstdint>

namespace hum::reconstruction::reach::map_context_getter_private {

struct dependencies {
    void* user;
    std::uint64_t module_base;
    std::uint64_t (*read_gs_58)(void* user);
    std::uint64_t (*read_u64)(void* user, std::uint64_t address);
    std::uint32_t (*read_u32)(void* user, std::uint64_t address);
    std::uint8_t (*read_u8)(void* user, std::uint64_t address);
};

std::uint64_t map_context_getter(const dependencies& reads);

}
