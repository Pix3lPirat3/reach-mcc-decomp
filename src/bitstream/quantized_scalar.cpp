#include "quantized_scalar.hpp"
#include <bit>
#include <immintrin.h>
#ifndef RECON671_ENTRY
#define RECON671_ENTRY body_dc234
#endif
#ifndef RECON671_MUTANT
#define RECON671_MUTANT 0
#endif
namespace hum::reconstruction::reach::recon671 {
namespace {
float subtract(float a, float b) { return _mm_cvtss_f32(_mm_sub_ss(_mm_set_ss(a), _mm_set_ss(b))); }
float divide(float a, float b) { return _mm_cvtss_f32(_mm_div_ss(_mm_set_ss(a), _mm_set_ss(b))); }
float signed_float(std::uint32_t n) { return _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_set1_epi32(std::bit_cast<std::int32_t>(n)))); }
std::int32_t integer(float n) { return _mm_cvttss_si32(_mm_set_ss(n)); }
std::int32_t signed_word(std::uint32_t n) { return std::bit_cast<std::int32_t>(n); }
}
Result RECON671_ENTRY(Memory& memory, Entry entry) {
    const auto width = memory.read32(entry.rsp + 0x30);
    const auto power = std::uint32_t{1} << (width & 31U);
    const auto first_flag = memory.read8(entry.rsp + 0x38);
    const auto limit = first_flag == 0 ? power : power - 1U;
    const auto second_flag = memory.read8(entry.rsp + 0x40);
    std::uint32_t payload = 0;
    std::uint32_t r11 = 1;
    if (second_flag != 0 && entry.xmm2 == entry.xmm3) {
#if RECON671_MUTANT == 1
        payload = limit - 1U;
#endif
    } else {
        const auto maximum = std::bit_cast<float>(memory.read32(entry.rsp + 0x28));
        if (second_flag != 0 && entry.xmm2 == maximum) payload = limit - 1U;
        else if (second_flag != 0) {
            payload = limit - 2U;
            const auto span = subtract(maximum, entry.xmm3);
            const auto divisor = signed_float(payload);
            const auto offset = subtract(entry.xmm2, entry.xmm3);
            const auto step = divide(span, divisor);
            const auto quantized = divide(offset, step);
            const auto biased = static_cast<std::uint32_t>(integer(quantized)) + 1U;
            if (signed_word(biased) > 1) r11 = biased;
            if (signed_word(r11) <= signed_word(payload)) payload = r11;
        } else {
            const auto offset = subtract(entry.xmm2, entry.xmm3);
            const auto span = subtract(maximum, entry.xmm3);
            const auto divisor = signed_float(limit);
            const auto step = divide(span, divisor);
            auto quantized = integer(divide(offset, step));
            if (quantized <= 0) quantized = 0;
            payload = limit - 1U;
            if (quantized <= signed_word(payload)) payload = static_cast<std::uint32_t>(quantized);
        }
    }
#if RECON671_MUTANT == 2
    payload &= power - 1U;
#endif
    const auto occupied = memory.read32(entry.stream + 0x30);
    const bool tail = signed_word(width) > signed_word(64U - occupied);
    if (tail) {
        const auto result = flush_native_bitstream(memory, entry.stream, payload, width, r11);
        return {payload, result.rdx_bits, result.r11_bits, true};
    }
    const auto requested = memory.read32(entry.stream + 0x24);
    memory.write32(entry.stream + 0x24, requested + width);
    memory.write32(entry.stream + 0x30, occupied + width);
    auto old = memory.read64(entry.stream + 0x28);
#if RECON671_MUTANT == 3
    if (width >= 64U) old = 0;
#endif
    memory.write64(entry.stream + 0x28, (old << (width & 63U)) | payload);
    return {payload, payload, r11, false};
}
}
