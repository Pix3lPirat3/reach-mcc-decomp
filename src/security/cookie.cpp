#include "cookie_core.hpp"
namespace hum::reconstruction::reach {
security_cookie_result check_security_cookie_787e00(security_cookie_memory& memory,
    std::uint64_t module,map_record_query_registers incoming) {
    const auto result=cookie_shared_detail::check_cookie(memory,module,incoming);
    return {result.registers,result.disposition,result.tail_target};
}
}
