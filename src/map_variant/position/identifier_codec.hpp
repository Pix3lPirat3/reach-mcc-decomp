#pragma once
#include "../../bitstream/native_writer.hpp"
#include "../../security/cookie.hpp"

namespace hum::reconstruction::reach::identifier_codec410 {
using address = std::uint64_t;
struct classify_call {
    address rcx;
    std::uint32_t edx;
    address r8, r9, fifth, sixth, seventh;
    bool operator==(const classify_call&) const = default;
};
struct scalar_call {
    address rcx, rdx;
    std::uint32_t r8d;
    bool operator==(const scalar_call&) const = default;
};
struct dependencies : native_bitstream_writer_memory, security_cookie_memory {
    virtual std::uint8_t read8(address) = 0;
    virtual std::uint64_t read64(address) override = 0;

    virtual void classify_3c6494(const classify_call&) = 0;
    virtual void scalar_f635c(const scalar_call&) = 0;
};

struct workspace { address working_rsp; map_record_query_registers cookie_carriers; };

struct encode_result { security_cookie_disposition cookie; address rdx; };
encode_result encode_continuation(dependencies&, address module_base,
    address stream, address identifier, std::uint32_t kind, address context, workspace);
security_cookie_disposition encode(dependencies&, address module_base,
    address stream, address identifier, std::uint32_t kind, address context,
    workspace);
}
