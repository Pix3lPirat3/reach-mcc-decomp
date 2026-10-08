#include "identifier_codec.hpp"

namespace hum::reconstruction::reach::identifier_codec410 {
encode_result encode_continuation(dependencies& m, address module,
    address stream, address identifier, std::uint32_t kind, address context,
    workspace frame) {
    const address rbp = frame.working_rsp + 0x70;
    const auto cookie = m.read64(module + 0xafa010);
    m.write64(rbp - 8, cookie ^ frame.working_rsp);
    m.write8(rbp - 0x30, 1);
    m.write32(rbp - 0x2c, 0xfffffffeU);
    m.write64(rbp - 0x18, 0);
    m.write32(rbp - 0x10, 0);
    m.write32(rbp - 0x28, 16);
    m.write32(rbp - 0x24, 16);
    m.write32(rbp - 0x20, 16);
    m.write64(frame.working_rsp + 0x30, rbp - 0x18);
    m.write64(frame.working_rsp + 0x28, rbp - 0x28);
    m.write64(frame.working_rsp + 0x20, rbp - 0x2c);
    m.classify_3c6494({identifier, kind, context, rbp - 0x30,
        rbp - 0x2c, rbp - 0x28, rbp - 0x18});
    std::uint64_t rdx = m.read8(rbp - 0x30) & 1U;
    const auto used = m.read32(stream + 0x30);
    if (used < 64U) {
        m.write32(stream + 0x24, m.read32(stream + 0x24) + 1U);
        m.write32(stream + 0x30, used + 1U);
        m.write64(stream + 0x28, (m.read64(stream + 0x28) << 1) | rdx);
    } else {
        rdx = flush_native_bitstream(m, stream, rdx, 1, 0).rdx_bits;
    }
    const auto flag = m.read8(rbp - 0x30);
#ifdef RECON410_MASK_FLAG_GATE
    if ((flag & 1U) == 0)
#else
    if (flag == 0)
#endif
        m.scalar_f635c({stream, rdx, m.read32(rbp - 0x2c)});
    for (address offset = 0; offset < 12; offset += 4) {
        const auto occupancy = m.read32(stream + 0x30);
#ifndef POSITION_OMIT_OCCUPANCY_RDX
        rdx = occupancy;
#endif
        const auto width = m.read32(rbp + offset - 0x28);
        const auto value = m.read32(rbp + offset - 0x18);
        const auto free = std::uint32_t{64} - occupancy;
#ifdef RECON410_UNSIGNED_WIDTH
        const bool slow = width > free;
#else
        const bool slow = (width ^ 0x80000000U) > (free ^ 0x80000000U);
#endif
        if (slow) {
            const auto flushed = flush_native_bitstream(m, stream, value, width, 0);
#ifndef POSITION_OMIT_FLUSH_RDX
            rdx = flushed.rdx_bits;
#else
            (void)flushed;
#endif
        } else {
            m.write32(stream + 0x24, m.read32(stream + 0x24) + width);
            m.write32(stream + 0x30, occupancy + width);
            auto field = std::uint64_t{value};
#ifdef RECON410_MASK_VALUE
            field &= 0xffffU;
#endif
            m.write64(stream + 0x28,
                (m.read64(stream + 0x28) << (width & 63U)) | field);
        }
    }
    auto carriers = frame.cookie_carriers;
    carriers.rcx = m.read64(rbp - 8) ^ frame.working_rsp;
    carriers.rdx = rdx;
    const auto checked = check_security_cookie_787e00(m, module, carriers);
    return {checked.disposition, checked.registers.rdx};
}
security_cookie_disposition encode(dependencies& m, address module,
    address stream, address identifier, std::uint32_t kind, address context, workspace frame) {
    return encode_continuation(m,module,stream,identifier,kind,context,frame).cookie;
}
}
