#pragma once

#include "../../common/datum_lookup.hpp"
#include <cstdint>

namespace hum::reconstruction::reach {
struct map_record_query_registers {
    std::uint64_t rax, rcx, rdx, r8, r9, r10, r11;
    bool operator==(const map_record_query_registers&) const = default;
};
struct map_record_query_dependencies : datum_lookup_memory {

    virtual map_record_query_registers copy_794276(map_record_query_registers) = 0;
};

map_record_query_registers query_map_record_124d4(map_record_query_dependencies&,
    std::uint64_t owner, std::uint64_t key_bits, std::uint64_t working_rsp,
    std::uint64_t incoming_r8, std::uint64_t incoming_r9,
    std::uint64_t incoming_r10, std::uint64_t incoming_r11);
}
