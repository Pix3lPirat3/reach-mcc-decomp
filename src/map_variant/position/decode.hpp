#pragma once
#include <array>
#include <cstdint>
namespace hum::reconstruction::reach::recon1550 {
using address = std::uint64_t;
using lanes = std::array<std::uint32_t,4>;
struct state {
    std::uint64_t rax,rcx,rdx,r8,r9,r10,r11;
    std::array<lanes,6> xmm;
};
enum class scalar_sse { sub, div, mul, add };
struct dependencies {
    virtual ~dependencies() = default;
    virtual std::uint8_t read8(address)=0;
    virtual std::uint32_t read32(address)=0;
    virtual std::uint64_t read64(address)=0;
    virtual void write32(address,std::uint32_t)=0;
    virtual void write64(address,std::uint64_t)=0;

    virtual std::uint32_t sse32(scalar_sse,std::uint32_t,std::uint32_t)=0;
    virtual lanes cvtdq2ps(const lanes& signed_dword_bits)=0;

    virtual state call_54214(state)=0;
    virtual state call_dd10c(state)=0;
    virtual state call_3c9a68(state)=0;
    virtual state call_3c9a0c(state)=0;
    virtual state call_787e00(state)=0;
};

state decode(dependencies&,address module,address frame,state incoming);
}
