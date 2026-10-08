#include "ceilf_adapter.hpp"
#include <stdexcept>
namespace hum::reconstruction::reach::recon1008 {
bool ceilf_finite_bits(std::uint32_t input, std::uint32_t& output) {
    const auto magnitude = input & 0x7fffffffU;
    const auto exponent = magnitude >> 23;
    if (exponent == 255) return false;
    if (magnitude == 0 || exponent >= 150) { output = input; return true; }
    const bool negative = (input >> 31) != 0;
    if (exponent < 127) {
        output = negative ? 0x80000000U : 0x3f800000U;
        return true;
    }
    const auto unit = std::uint32_t{1} << (150 - exponent);
    const auto mask = unit - 1;
    auto integral = magnitude & ~mask;
    if (!negative && (magnitude & mask)) integral += unit;
    output = (input & 0x80000000U) | integral;
    return true;
}
std::uint32_t FiniteCeilfAdapter::call91a13e(std::uint32_t input) {
    std::uint32_t output;
    if (!ceilf_finite_bits(input, output))
        throw std::domain_error("RECON-1008 finite ceilf domain excluded");
    return output;
}
}
