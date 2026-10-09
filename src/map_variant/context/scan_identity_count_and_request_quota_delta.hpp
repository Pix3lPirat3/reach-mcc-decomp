#pragma once
#include <cstdint>

namespace hum::reach::recon390 {

struct Registers {
    std::uint64_t rax, rcx, rdx, r8, r9, r10, r11;
};
struct Dependencies {
    void* context;
    std::uint64_t (*read)(void*, std::uint64_t address, unsigned width);
    std::uint64_t (*read_gs58)(void*);

    void (*call)(void*, std::uint32_t target, std::uint32_t site, Registers&);
};
inline constexpr std::uint32_t tls_index_rva = 0xc17b18;
void scan_identity_count_and_request_quota_delta(Registers&, const Dependencies&, std::uint64_t module_base);
}
