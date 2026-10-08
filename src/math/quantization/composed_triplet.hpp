#pragma once
#include "triplet.hpp"
#include "clamp.hpp"
namespace hum::recon724 {
using namespace hum::reconstruction::reach;

struct Transport {
    virtual ~Transport() = default;
    virtual comparison556 call93634(triplet556&,std::uint64_t,carriers556)=0;
    virtual void call3c9a68(std::uint32_t,std::uint64_t,std::uint64_t,std::uint64_t)=0;
};

carriers556 clamp_local724(native_bitstream_writer_memory&,triplet556&,
    std::uint64_t local_token,std::uint64_t bounds,std::uint64_t input,carriers556);
void prepare724(native_bitstream_writer_memory&,Transport&,const inputs556&);
}
