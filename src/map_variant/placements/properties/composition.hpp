#pragma once
#include "../scalars.hpp"
#include <span>

namespace hum::reconstruction::reach::properties_composition {
using address = std::uint64_t;
using memory = hum::reconstruction::reach::placement_scalars::memory;
struct range { address begin, size; };
struct admission {

    std::span<const range> guest;
    address private_rsp;
};

void encode(memory&, address module, address source, address stream, admission);
void control_frame(memory&, address, address, address, admission);
void control_order(memory&, address, address, address, admission);
void control_magnitude(memory&, address, address, address, admission);
}
