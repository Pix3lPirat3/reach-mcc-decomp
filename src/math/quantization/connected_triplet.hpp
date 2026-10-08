#pragma once
#include "triplet.hpp"
#include "triplet_comparison/interface.hpp"
namespace hum::reconstruction::reach {

struct transport727 {
    virtual ~transport727() = default;
    virtual carriers556 call1de64(std::uint64_t,std::uint64_t,triplet556&,carriers556) = 0;
    virtual void call3c9a68(std::uint32_t,std::uint64_t,std::uint64_t,std::uint64_t) = 0;
};
void prepare_connected_triplet727(native_bitstream_writer_memory&,transport727&,
    const inputs556&,std::uint64_t constant_address);
}
