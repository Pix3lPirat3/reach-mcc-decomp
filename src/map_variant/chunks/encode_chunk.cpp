#include "encode_chunk.hpp"

namespace hum::reconstruction::reach::chunk_encoder477 {
namespace {
std::uint32_t reverse32(std::uint32_t v) {
    return (v >> 24) | ((v >> 8) & 0xff00U)
        | ((v << 8) & 0xff0000U) | (v << 24);
}
}
std::uint64_t encode(dependencies& m, address module_base, address chunk,
                     address variant, workspace frame) {
    const auto payload = chunk + 0x24;
    const auto stream = frame.frame_rsp + 0x40;
    const auto hash_state = frame.frame_rsp + 0x110;
    const auto count_storage = frame.frame_rsp + 0x30;

    (void)m.read32(chunk + 0x20);
    m.write32(chunk + 0x20, 0);
    m.write32(chunk + 0x7024, 0);
    (void)m.fill_at_78932a(payload, 0, 0x7000);
    m.write64(stream, payload);
    m.write64(stream + 8, payload + 0x7000);
    m.write32(stream + 0x14, 1);
    m.write32(stream + 0x10, 0x7000);
    const auto first = setup_bitstream(m, stream,
        {payload + 0x7000, 0, 0, 1, frame.frame_rsp - 8});
    const auto r11d = static_cast<std::uint32_t>(first.r11_bits);
    m.write32(stream + 0x14, r11d);
    (void)setup_bitstream(m, stream,
        {first.rax_bits, r11d, first.r10_bits, first.r11_bits, frame.frame_rsp - 8});
    m.encode_variant_6d04c(variant, stream);
    const auto finished = finalize_bitstream(m, stream);

    const auto occupied = m.read32(stream + 0x30);
    const auto total = m.read32(stream + 0x20);
    const std::uint32_t sum = total + occupied + 7U;
    const std::uint32_t biased = sum + ((sum & 0x80000000U) ? 7U : 0U);
    const std::uint32_t count = (biased >> 3)
        | ((biased & 0x80000000U) ? 0xe0000000U : 0U);
#ifdef RECON477_WRONG_LENGTH
    m.write32(chunk + 0x20, reverse32(count + 1U));
#else
    m.write32(chunk + 0x20, reverse32(count));
#endif
    m.write32(chunk, 0x7261766dU);
    m.write32(chunk + 4, 0x28700000U);
    m.write32(chunk + 8, 0x01001f00U);
    auto raw = crypto_hash_wrappers::initialize_2037c(m, module_base, hash_state,
        0x58, {frame.frame_rsp - 0x50, finished.r9_bits});
    if ((raw & 0xffU) != 0) {
        const auto reloaded_count = reverse32(m.read32(chunk + 0x20));
#ifdef RECON477_REORDER_HANDLE
        m.write32(count_storage, reloaded_count);
        const auto handle1 = m.read64(hash_state);
#else

        const auto handle1 = m.read64(hash_state);
        m.write32(count_storage, reloaded_count);
#endif
        const auto status1 = m.hash_data(handle1, count_storage, 4, 0);
#ifdef RECON477_WRONG_STATUS_GUARD
        if ((status1 & 0x80000000U) != 0) return status1;
#else
        (void)status1;
#endif
        const auto length2 = m.read32(count_storage);
        const auto handle2 = m.read64(hash_state);
        (void)m.hash_data(handle2, payload, length2, 0);
        raw = crypto_hash_wrappers::finalize_20420(m, hash_state, chunk + 0xc);
    } else {
        raw = 0;
#ifndef RECON477_SKIP_FAILURE_DIGEST
        m.write64(chunk + 0xc, 0);
        m.write64(chunk + 0x14, 0);
        m.write32(chunk + 0x1c, 0);
#endif
    }
    return raw;
}
}
