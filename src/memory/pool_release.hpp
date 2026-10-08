#pragma once
#include "../common/synchronization_pair.hpp"

namespace hum::reconstruction::reach::recon1519 {
using address = std::uint64_t;
using carriers = synchronization_pair::carriers;
struct dependencies {
    virtual ~dependencies() = default;
    virtual std::uint32_t read32(address) = 0;
    virtual std::uint64_t read64(address) = 0;
    virtual void write32(address, std::uint32_t) = 0;
    virtual void write64(address, std::uint64_t) = 0;
};

carriers release(dependencies&, carriers incoming);
}
