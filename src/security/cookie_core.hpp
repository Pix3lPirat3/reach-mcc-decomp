#pragma once
#include "cookie.hpp"
#include <bit>

namespace hum::reconstruction::reach::cookie_shared_detail {
template<class State> struct result {
    State registers;security_cookie_disposition disposition;std::uint64_t tail_target;
};
template<class Memory,class State>
result<State> check_cookie(Memory& memory,std::uint64_t module_base,State incoming) {
    const auto expected = memory.read64(module_base + 0xafa010u);
    if (incoming.rcx == expected) {
        incoming.rcx = std::rotl(static_cast<std::uint64_t>(incoming.rcx), 16);
        if ((incoming.rcx & 0xffffu) == 0u)
            return {incoming, security_cookie_disposition::normal_return, 0};
        incoming.rcx = std::rotr(static_cast<std::uint64_t>(incoming.rcx), 16);
    }
    return {incoming, security_cookie_disposition::tail_transfer, module_base + 0x788a78u};
}
}
