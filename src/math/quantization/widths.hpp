#pragma once
#include "../../bitstream/native_writer.hpp"
#include "../../security/cookie.hpp"
#include <cstdint>

namespace hum::reconstruction::reach {
struct memory624 : native_bitstream_writer_memory, security_cookie_memory {
    virtual std::uint64_t read64(std::uint64_t address) override = 0;
};
struct dependencies624 {
    virtual ~dependencies624() = default;

    virtual std::uint32_t call91a13e(std::uint32_t xmm0_bits) = 0;
};
struct inputs624 {
    std::uint32_t raw_width;
    std::uint64_t bounds, output, scale_constant, threshold_constant, module;
};
struct result624 {
    std::uint64_t rax;
    security_cookie_disposition cookie;
    std::uint64_t tail_target;
    bool operator==(const result624&) const = default;
};

result624 quantized_widths624(memory624&, dependencies624&, const inputs624&);
}
