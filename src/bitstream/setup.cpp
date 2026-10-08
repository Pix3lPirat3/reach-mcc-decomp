#include "setup.hpp"

namespace hum::reconstruction::reach {
bitstream_setup_continuation setup_bitstream(
    bitstream_setup_memory& memory, bitstream_setup_address stream,
    bitstream_setup_input input) {
    bitstream_setup_continuation r{
        input.rax_bits, stream, input.rdx_bits, 0, stream,
        input.r10_bits, input.r11_bits};
    const auto mode = static_cast<std::uint32_t>(r.rdx_bits);
    memory.write32(stream + 0x18, mode);
    memory.write64(stream + 0x20, 0);
    memory.write32(stream + 0x40, 0);
    memory.write8(stream + 0x1c, 0);
    r.rcx_bits = memory.read64(stream);
    memory.write64(stream + 0x38, r.rcx_bits);
    memory.write64(stream + 0x28, 0);
    memory.write32(stream + 0x30, 0);
    if (mode == 1) {
        memory.write64(stream + 0xc8, 0);
        return r;
    }
    r.rax_bits = mode - std::uint32_t{3};
    if (r.rax_bits > 1) return r;
    r.r10_bits = r.rcx_bits + 8;
    if (r.r10_bits <= memory.read64(stream + 8)) {
        r.rdx_bits = memory.read64(r.rcx_bits);
        r.rax_bits = 0x00ff000000000000ULL;
        r.r8_bits = r.rdx_bits;
        memory.write64(stream + 0x38, r.r10_bits);

        r.r8_bits &= r.rax_bits;
        r.rcx_bits = 0x0000ff0000000000ULL;
        r.rax_bits = r.rdx_bits >> 16;
        r.r8_bits |= r.rax_bits;
        r.rax_bits = r.rdx_bits & r.rcx_bits;
        r.r8_bits >>= 16;
        r.r8_bits |= r.rax_bits;
        r.rcx_bits = 0x000000ff00000000ULL;
        r.rax_bits = r.rdx_bits;
        r.r8_bits >>= 16;
        r.rax_bits &= r.rcx_bits;
        r.rcx_bits = r.rdx_bits;
        r.r8_bits |= r.rax_bits;
        r.rcx_bits <<= 16;
        r.rax_bits = r.rdx_bits;
        r.r8_bits >>= 8;
        r.rax_bits = static_cast<std::uint32_t>(r.rax_bits) & 0xff00U;
        r.rcx_bits |= r.rax_bits;
        r.rax_bits = r.rdx_bits;
        r.rcx_bits <<= 16;
        r.rax_bits = static_cast<std::uint32_t>(r.rax_bits) & 0xff0000U;
        r.rcx_bits |= r.rax_bits;
        r.rax_bits = 0xff000000U;
        r.rdx_bits &= r.rax_bits;
        r.rcx_bits <<= 16;
        r.rcx_bits |= r.rdx_bits;
        r.rdx_bits = 64;
        r.rcx_bits <<= 8;
        r.r8_bits |= r.rcx_bits;
    } else if (r.rcx_bits < memory.read64(stream + 8)) {
        r.rdx_bits = 0;
        do {
            r.rax_bits = memory.read8(r.rcx_bits);
            r.rdx_bits = static_cast<std::uint32_t>(r.rdx_bits) + std::uint32_t{8};
            r.r8_bits <<= 8;
            ++r.rcx_bits;
            r.r8_bits |= r.rax_bits;
            memory.write64(stream + 0x38, r.rcx_bits);
        } while (r.rcx_bits < memory.read64(stream + 8));
        r.rcx_bits = static_cast<std::uint8_t>(64U - static_cast<std::uint8_t>(r.rdx_bits));
        r.r8_bits <<= r.rcx_bits & 63U;
    } else {
        r.rdx_bits = memory.read32(input.entry_rsp + 0x10);
    }
    memory.write32(stream + 0x20, static_cast<std::uint32_t>(r.rdx_bits));
    memory.write64(stream + 0x28, r.r8_bits);
    return r;
}
}
