#pragma once
#include "kernel.hpp"
#include <optional>
namespace hum::reconstruction::reach::local1856c {
struct effects_memory : memory {

    virtual bool owns(address,std::uint64_t width) const = 0;
};
struct effects_request {
    address destination,reference;
    std::optional<std::uint32_t> coefficient2_low,coefficient3_low;
};
enum class effects_outcome { completed,ownership_refused,domain_refused,
                             fp_environment_refused,unavailable_consumed_input };

effects_outcome project_effects(effects_memory&,address module,effects_request);
}
