#pragma once
#include <cstdint>
namespace recon453 {
struct Memory {
    virtual ~Memory() = default;
    virtual std::uint64_t read(std::uint64_t address, unsigned bytes) = 0;
    virtual void write(std::uint64_t address, unsigned bytes, std::uint64_t value) = 0;
};
struct Entry { std::uint64_t rsp, rcx, rdx, r10, r11; };
struct Call6cfd0 { std::uint64_t rax, rcx, rdx, r8, r9, r10, r11; };
struct Continuation { std::uint64_t r10, r11; };
struct Dependency {
    virtual ~Dependency() = default;
    virtual Continuation call_6cfd0(Memory&, const Call6cfd0&) = 0;
};
struct Result { std::uint64_t rax, rcx, rdx, r8, r9, r10, r11; };
enum class Mutant { none, unsigned_first, unsigned_second, masked_tag, first_stride_four, stale_first };

Result body_6cf60(Memory&, Dependency&, std::uint64_t module, Entry,
                 Mutant mutant = Mutant::none);
}
