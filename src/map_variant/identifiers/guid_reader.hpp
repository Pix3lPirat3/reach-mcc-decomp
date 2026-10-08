#pragma once
#include <cstdint>

namespace hum::reconstruction::reach {
using guid_reader_address = std::uint64_t;
struct guid_reader_dependencies {
    virtual ~guid_reader_dependencies() = default;

    virtual std::uint8_t read8(guid_reader_address) = 0;
    virtual std::uint32_t read32(guid_reader_address) = 0;
    virtual std::uint64_t read64(guid_reader_address) = 0;
    virtual void write16(guid_reader_address,std::uint16_t) = 0;
    virtual void write32(guid_reader_address,std::uint32_t) = 0;
    virtual void write64(guid_reader_address,std::uint64_t) = 0;

    virtual std::uint32_t empty_refill_private_word(std::uint32_t leaf_rva,
        std::uint32_t call_ordinal) = 0;
};
struct guid_reader_continuation {
    std::uint64_t rax_bits;
    std::uint64_t rdx_bits;
    std::uint64_t r8_bits;
};

guid_reader_continuation read_map_guid_native_projection(guid_reader_dependencies& dependencies,
    guid_reader_address reader,guid_reader_address destination16);
}
