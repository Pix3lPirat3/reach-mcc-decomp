#pragma once
#include "lookup_6cf60.hpp"

namespace recon515 {
using Memory = recon453::Memory;
struct Entry {
    std::uint64_t rsp, rbx, rdi, rcx, rdx, r8, r9;
};
struct Result {
    std::uint64_t rax, rcx, rdx, r8, r9, r10, r11, rbx, rdi;
};
enum class Mutant { none, unsigned_compare, cached_subtract, masked_tag,
    clear_miss, reverse_outputs, stride_four };

Result body_6cfd0(Memory&, std::uint64_t module, Entry,
                 Mutant mutant = Mutant::none);
}
