#pragma once
#include <array>
#include <cstdint>
#include <optional>
#include "../reset.hpp"

namespace hum::reconstruction::reach::parent_options {
using address=std::uint64_t;
using vector128=std::array<std::uint8_t,16>;
struct memory {
    virtual ~memory()=default;
    virtual std::uint64_t read(address,unsigned width)=0;
    virtual vector128 read128(address)=0;
    virtual void write(address,unsigned width,std::uint64_t)=0;
    virtual void write128(address,const vector128&)=0;
};

struct continuation { std::uint64_t token; bool operator==(const continuation&) const=default; };
struct result {
    std::optional<std::uint64_t> raw_rax;
    continuation provider_state;
    bool operator==(const result&) const=default;
};
struct dependencies {
    virtual ~dependencies()=default;
    virtual continuation fill_78932a(memory&,address,std::uint32_t value,std::uint32_t size,continuation)=0;
    virtual continuation call_3a92d8(memory&,std::uint32_t ecx,address rdx,continuation)=0;
    virtual continuation call_37334(memory&,address rcx,std::uint32_t edx,continuation)=0;
    virtual continuation call_42d4c(memory&,address rcx,continuation)=0;
    virtual result reset_6c080(memory&,address rcx,std::uint32_t edx,continuation)=0;
    virtual result validate_6c948(memory&,address rcx,std::uint32_t edx,continuation)=0;
};

result initialize(memory&,dependencies&,address module,address parent,continuation);
result sanitize(memory&,dependencies&,address parent,continuation);

result control_align_initialize(memory&,dependencies&,address,address,continuation);
result control_align_sanitize(memory&,dependencies&,address,continuation);
result control_extent_initialize(memory&,dependencies&,address,address,continuation);
result control_extent_sanitize(memory&,dependencies&,address,continuation);
result control_tail_initialize(memory&,dependencies&,address,address,continuation);
result control_tail_sanitize(memory&,dependencies&,address,continuation);

result compose_reset(map_variant_reset_dependencies&,address variant,std::uint32_t id,
                     address module,address rbp,continuation);
}
