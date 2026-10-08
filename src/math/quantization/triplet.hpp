#pragma once
#include "../../bitstream/native_writer.hpp"
#include <array>
namespace hum::reconstruction::reach {
using triplet556 = std::array<std::uint32_t,3>;

struct carriers556 { std::uint64_t rdx,r8,r9,r10,r11; };
struct comparison556 { std::uint8_t al; carriers556 next; };
struct dependencies556 {
    virtual ~dependencies556() = default;
    virtual comparison556 call93634(triplet556& local,std::uint64_t target,
        carriers556 incoming) = 0;
    virtual carriers556 call1de64(std::uint64_t rcx,std::uint64_t rdx,
        triplet556& local,carriers556 incoming) = 0;
    virtual void call3c9a68(std::uint32_t rcx,std::uint64_t rdx,
        std::uint64_t r8,std::uint64_t r9) = 0;
};
struct inputs556 {
    std::uint64_t source,optional,flag,index,widths,output;
    std::uint32_t raw_width;
    std::uint64_t table,mask_address,fallback,local_address;
};

void prepare_quantized_triplet556(native_bitstream_writer_memory& memory,
    dependencies556& dependencies,const inputs556& inputs);
}
