#include "scalars.hpp"
#include <bit>

namespace hum::reconstruction::reach::placement_scalars {
namespace {
float f32(std::uint32_t bits) { return std::bit_cast<float>(bits); }
std::uint32_t bits32(float value) { return std::bit_cast<std::uint32_t>(value); }
std::uint32_t signed_byte(std::uint8_t value) {
    return value < 128u ? value : 0xffffff00u | value;
}
bool signed_less(std::uint32_t left, std::uint32_t right) {
    return (left ^ 0x80000000u) < (right ^ 0x80000000u);
}
}
continuation scalar(memory& m, imports& deps, address module, address stream,
                    std::uint32_t value, continuation state) {
    const auto bound = m.read32(module + 0xa8b4a8);
    auto x0 = state.xmm0_low;

    if (!(f32(value) < f32(bound))) {
        const float difference_zero = f32(value) - 0.0f;
        x0 = bits32(difference_zero);
        if (!(difference_zero >= 0.0f)) value = 0;
        const float difference_bound = f32(value) - f32(bound);
        x0 = bits32(difference_bound);
#ifndef RECON517_SKIP_UPPER
        if (!(difference_bound < 0.0f)) value = bound;
#endif
    }
    const boundary call{stream,x0,bound,value,0,bound,11,0,1};
    return deps.dc234(m,call,state);
}
continuation record(memory& m, imports& deps, address module, address source,
                    address stream, continuation state, std::uint64_t r11) {
    const auto occupied = m.read32(stream + 0x30);
    auto payload = signed_byte(m.read8(source + 0x10));
#ifdef RECON517_MASK_TAG
    payload &= 3u;
#endif
    if (signed_less(std::uint32_t{64} - occupied,2)) {
        const auto effect = flush_native_bitstream(m,stream,payload,2,r11);
        state.token = deps.writer_effect(state,effect);
    } else {
        const auto total = m.read32(stream + 0x24);
        m.write32(stream + 0x24,total + 2u);
        m.write32(stream + 0x30,occupied + 2u);
        const auto window = m.read64(stream + 0x28);
        m.write64(stream + 0x28,(window << 2) | std::uint64_t{payload});
    }
#ifdef RECON517_CACHE_TAG
    const auto kind = payload;
#else
    const auto kind = signed_byte(m.read8(source + 0x10));
#endif
    if (kind == 3u) {
        state = scalar(m,deps,module,stream,m.read32(source),state);
        state = scalar(m,deps,module,stream,m.read32(source + 4),state);
        state = scalar(m,deps,module,stream,m.read32(source + 8),state);

        const auto last = m.read32(source + 12);
        const double wide = static_cast<double>(f32(last));
        const auto mask = m.read128(module + 0xa8ce60);
        std::uint64_t low = 0;
        for (unsigned i=0;i<8;++i) low |= std::uint64_t{mask[i]} << (i*8u);
        const auto masked = std::bit_cast<std::uint64_t>(wide) & low;
        const float narrowed = static_cast<float>(std::bit_cast<double>(masked));
        state = scalar(m,deps,module,stream,bits32(narrowed),state);
    } else if (kind == 2u) {
        state = scalar(m,deps,module,stream,m.read32(source),state);
        state = scalar(m,deps,module,stream,m.read32(source + 8),state);
        const auto last = m.read32(source + 12);
        const double wide = static_cast<double>(f32(last));
        const auto mask = m.read128(module + 0xa8ce60);
        std::uint64_t low = 0;
        for (unsigned i=0;i<8;++i) low |= std::uint64_t{mask[i]} << (i*8u);
        const auto masked = std::bit_cast<std::uint64_t>(wide) & low;
        const float narrowed = static_cast<float>(std::bit_cast<double>(masked));
        state = scalar(m,deps,module,stream,bits32(narrowed),state);
    } else if (kind == 1u) {
        state = scalar(m,deps,module,stream,m.read32(source),state);
    }
    return state;
}
}
