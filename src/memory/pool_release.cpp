#include "pool_release.hpp"

namespace hum::reconstruction::reach::recon1519 {
carriers release(dependencies& d, carriers s) {
    s.rdx = static_cast<std::uint32_t>(s.rdx) - 0x10U;
    s.r8 = s.rdx;
    s.r8 += s.rcx;
    if (d.read32(s.rcx + 0x54) == static_cast<std::uint32_t>(s.rdx)) {
        s.rax = d.read32(s.r8 + 0xc);
        d.write32(s.rcx + 0x54, static_cast<std::uint32_t>(s.rax));
    }
    s.rax = d.read32(s.r8);
    const auto free_bytes = d.read64(s.rcx + 0x40);
    d.write64(s.rcx + 0x40, free_bytes + s.rax);
    const bool predecessor_zero = d.read32(s.r8 + 0xc) == 0;
    s.rdx = d.read32(s.r8 + 8);
    if (!predecessor_zero) {
        s.rax = d.read32(s.r8 + 0xc);
        d.write32(s.rax + s.rcx + 8, static_cast<std::uint32_t>(s.rdx));
    } else {
        d.write32(s.rcx + 0x4c, static_cast<std::uint32_t>(s.rdx));
    }
    const bool successor_zero = d.read32(s.r8 + 8) == 0;
    s.rdx = d.read32(s.r8 + 0xc);
    if (!successor_zero) {
        s.rax = d.read32(s.r8 + 8);
        d.write32(s.rax + s.rcx + 0xc, static_cast<std::uint32_t>(s.rdx));
        return s;
    }
    d.write32(s.rcx + 0x50, static_cast<std::uint32_t>(s.rdx));
    return s;
}
}
