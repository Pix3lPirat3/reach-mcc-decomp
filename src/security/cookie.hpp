#pragma once

#include "../map_variant/records/query.hpp"
#include <cstdint>

namespace hum::reconstruction::reach {
struct security_cookie_memory {
    virtual ~security_cookie_memory() = default;
    virtual std::uint64_t read64(std::uint64_t address) = 0;
};
enum class security_cookie_disposition { normal_return, tail_transfer };
struct security_cookie_result {
    map_record_query_registers registers;
    security_cookie_disposition disposition;
    std::uint64_t tail_target;
    bool operator==(const security_cookie_result&) const = default;
};

security_cookie_result check_security_cookie_787e00(security_cookie_memory&,
    std::uint64_t module_base, map_record_query_registers incoming);
}
