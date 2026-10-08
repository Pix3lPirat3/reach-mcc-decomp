#pragma once
#include "../placements/dependencies.hpp"

namespace hum::reach::initial_quota40 {
using U = std::uint64_t;
using Registers = recon1552::Registers;
using Memory = recon1552::Memory;
struct PrivateInputs { U metadata_entry_rsp, resolver_rbx, resolver_rdi; };
struct Calls {
    virtual ~Calls() = default;
    virtual Registers count(Memory&, U module, Registers) = 0;
    virtual Registers metadata(Memory&, U module, Registers, PrivateInputs) = 0;
};

struct ProviderCalls final : Calls {
    Registers count(Memory&, U, Registers) override;
    Registers metadata(Memory&, U, Registers, PrivateInputs) override;
};
struct Result { Registers boundary; bool quota_match; U iterations; };

Result initialize(Memory&, Calls&, U module, U destination, U source,
                  U saved_root, Registers boundary, PrivateInputs);
}
