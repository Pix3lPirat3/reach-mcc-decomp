#pragma once
#include "../placements/dependencies.hpp"
#include <array>
namespace hum::reach::transfer21 {
using U=std::uint64_t;
using Registers=recon1552::Registers;
struct Memory : recon1552::StringDependencies {
    virtual std::array<std::uint8_t,16> read128(U)=0;
    virtual void write128(U,const std::array<std::uint8_t,16>&)=0;
};
struct PrivateInputs {
    U metadata_entry_rsp,remap_entry_rsp,resolver_rbx,resolver_rdi;
};
struct Result {Registers boundary;U accepted_records,accepted_bytes;};

Result compact_records(Memory&,U module,U destination,U source,bool match,
    Registers boundary,PrivateInputs);
}
