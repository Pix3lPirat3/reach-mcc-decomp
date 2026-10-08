#pragma once
#include <array>
#include <cstdint>
namespace hum::recon525 {
using address = std::uint64_t;
struct Memory {
    virtual ~Memory() = default;
    virtual std::uint32_t read32(address) = 0;
    virtual std::array<std::uint8_t,16> read128(address) = 0;
    virtual void write32(address,std::uint32_t) = 0;
};
struct Continuation { std::uint32_t xmm0_low; std::uint64_t token; };
struct CallBoundary {
    address vector;
    std::uint32_t xmm0_low, xmm1_low, xmm2_low;
};
struct Dependency {
    virtual ~Dependency() = default;

    virtual Continuation call_91a19e(Memory&,CallBoundary,Continuation) = 0;
};

Continuation vector_helper(Memory&,Dependency&,address module,address vector,Continuation);
Continuation mutant_sum(Memory&,Dependency&,address,address,Continuation);
Continuation mutant_tie(Memory&,Dependency&,address,address,Continuation);
Continuation mutant_store(Memory&,Dependency&,address,address,Continuation);
}
