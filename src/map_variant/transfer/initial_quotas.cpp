#include "initial_quotas.hpp"
#include "../lookups/lookup_6cf60.hpp"
#include "../lookups/lookup_6cfd0.hpp"

namespace hum::reach::initial_quota40 {
namespace {
U dword(U x) { return static_cast<std::uint32_t>(x); }
std::int64_t signed32(U x) {
    const U word = dword(x);
    return word <= 0x7fffffffU ? static_cast<std::int64_t>(word)
                            : static_cast<std::int64_t>(word) - 0x100000000LL;
}
U word_as_eax(U x) {
    const U word = x & 65535U;
    return word < 32768U ? word : word | 0xffff0000U;
}
struct ReaderMemory final : recon453::Memory {
    hum::reach::initial_quota40::Memory& ram;
    explicit ReaderMemory(hum::reach::initial_quota40::Memory& m) : ram(m) {}
    U read(U a, unsigned n) override { return ram.read(a, n); }
    void write(U a, unsigned n, U v) override { ram.write(a, n, v); }
};
struct Resolver final : recon453::Dependency {
    U module;
    PrivateInputs frames;
    Resolver(U base, PrivateInputs f) : module(base), frames(f) {}
    recon453::Continuation call_6cfd0(recon453::Memory& ram,
                                     const recon453::Call6cfd0& c) override {
        const auto result = recon515::body_6cfd0(ram, module,
            {c.r8 - 0x38U, frames.resolver_rbx, frames.resolver_rdi,
             c.rcx, c.rdx, c.r8, c.r9});
        return {result.r10, result.r11};
    }
};
}
Registers ProviderCalls::count(Memory& ram, U module, Registers r) {
    return recon1552::sum_6c710(ram, r, module);
}
Registers ProviderCalls::metadata(Memory& ram, U module, Registers r,
                                  PrivateInputs frames) {
    ReaderMemory adapter(ram);
    Resolver resolver(module, frames);
    const auto result = recon453::body_6cf60(adapter, resolver, module,
        {frames.metadata_entry_rsp, r.rcx, r.rdx, r.r10, r.r11});
    return {result.rax, result.rcx, result.rdx, result.r8,
            result.r9, result.r10, result.r11};
}
Result initialize(Memory& ram, Calls& calls, U module, U destination, U source,
                  U saved_root, Registers r, PrivateInputs frames) {
    bool quota_match = false;
    if (saved_root != 0U) {
        r.rax = dword(ram.read(source + 0x2b4U, 4));
        quota_match = dword(ram.read(saved_root + 0x10U, 4)) == r.rax;
    }
    if (quota_match) {
        r.rcx = saved_root;
        r = calls.count(ram, module, r);
    } else {
        r.rax = ram.read(source + 0x2b2U, 2) & 65535U;
    }
    ram.write(destination + 0x2b2U, 2, r.rax & 65535U);
    std::uint32_t index = 0;
    U iterations = 0;
    if (signed32(word_as_eax(r.rax)) <= 0) return {r, quota_match, iterations};
    U cursor = destination + 0xd641U;
    for (;;) {
        r.rax = word_as_eax(ram.read(source + 0x2b2U, 2));
        if (signed32(index) < signed32(r.rax)) {
            r.rcx = cursor;
            r.rcx -= destination;
            r.rax = ram.read(r.rcx + source - 1U, 2) & 65535U;
            ram.write(cursor - 1U, 2, r.rax);
            ram.write(cursor + 1U, 1, 0);
            if (quota_match) {
                r.rdx = index;
                r = calls.metadata(ram, module, r, frames);
                r.rdx = dword(ram.read(r.rax + 0x10U, 4));
                r.rcx = ram.read(cursor, 1) & 255U;
                r.r8 = r.rdx & 255U;
                if (signed32(r.rcx) <= signed32(r.rdx)) r.r8 = r.rcx;
                ram.write(cursor, 1, r.r8 & 255U);
            } else {
                r.r8 = (r.r8 & ~U{255}) | (ram.read(cursor, 1) & 255U);
            }
            r.rcx = r.r8 & 255U;
            r.rax = ram.read(cursor - 1U, 1) & 255U;
            if ((r.rax & 255U) <= (r.rcx & 255U)) r.rcx = dword(r.rax);
            ram.write(cursor - 1U, 1, r.rcx & 255U);
        } else {
            ram.write(cursor - 1U, 2, 0);
            ram.write(cursor + 1U, 1, 0);
        }
        ++index;
        cursor += 3U;
        r.rax = word_as_eax(ram.read(destination + 0x2b2U, 2));
        ++iterations;
        if (signed32(index) >= signed32(r.rax)) break;
    }
    return {r, quota_match, iterations};
}
}
