#pragma once
#include "../quantization/widths.hpp"
namespace hum::reconstruction::reach::recon1008 {

bool ceilf_finite_bits(std::uint32_t input, std::uint32_t& output);

struct FiniteCeilfAdapter final : dependencies624 {
    std::uint32_t call91a13e(std::uint32_t input) override;
};
}
