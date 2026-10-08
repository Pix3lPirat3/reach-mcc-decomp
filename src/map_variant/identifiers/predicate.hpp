#pragma once
#include <cstdint>

namespace hum::reconstruction::reach::identifier_predicate {
using address = std::uint64_t;

struct dependencies {
    virtual ~dependencies() = default;
    virtual std::uint8_t read8(address location) = 0;
    virtual std::uint16_t read16(address location) = 0;
    virtual std::uint32_t read32(address location) = 0;
};

struct result {
    std::uint64_t rax;
    std::uint64_t rdx;
    std::uint64_t r8;
    std::uint8_t al() const { return static_cast<std::uint8_t>(rax); }
    bool nonzero() const { return al() != 0; }
    bool operator==(const result&) const = default;
};

result evaluate_d114(dependencies& memory, address input,
    std::uint64_t incoming_rax, std::uint64_t incoming_rdx);
}
