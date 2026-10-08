#pragma once
#include "normalize.hpp"
namespace hum::recon529 {
using hum::recon525::address;
using hum::recon525::Continuation;
using hum::recon525::Dependency;
struct Memory : hum::recon525::Memory {
    virtual std::uint64_t read64(address) = 0;
    virtual void write64(address,std::uint64_t) = 0;
};

Continuation direction(Memory&,Dependency&,address module,std::int32_t index,
                       address output,std::int32_t selector,Continuation);
Continuation basis(Memory&,Dependency&,address module,address input,
                   address first,address second,Continuation);
Continuation mutant_center(Memory&,Dependency&,address,std::int32_t,address,std::int32_t,Continuation);
Continuation mutant_choice(Memory&,Dependency&,address,address,address,address,Continuation);
Continuation mutant_cross(Memory&,Dependency&,address,address,address,address,Continuation);
}
