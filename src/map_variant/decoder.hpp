#pragma once
#include <array>
#include <cstdint>
#include <optional>
#include <variant>
#include "payload/uncompressed_list_decode.hpp"

namespace hum::reconstruction::reach {
using map_decoder_address = std::uint64_t;
struct map_decoder_result { std::uint64_t rax_bits; std::uint64_t rdx_bits; };

struct map_variant_decoder_dependencies {
    virtual ~map_variant_decoder_dependencies() = default;
    virtual std::uint16_t read16(map_decoder_address) = 0;
    virtual std::uint32_t read32(map_decoder_address) = 0;
    virtual std::array<std::uint8_t,16> read128(map_decoder_address) = 0;
    virtual void write8(map_decoder_address,std::uint8_t) = 0;
    virtual void write16(map_decoder_address,std::uint16_t) = 0;
    virtual void write32(map_decoder_address,std::uint32_t) = 0;
    virtual void write64(map_decoder_address,std::uint64_t) = 0;
    virtual void write128(map_decoder_address,const std::array<std::uint8_t,16>&) = 0;

    virtual map_decoder_result call_103638(map_decoder_address reader,map_decoder_address variant) = 0;

    virtual map_decoder_result call_dd10c(map_decoder_address reader,std::uint32_t width) = 0;

    virtual map_decoder_result call_54214(map_decoder_address reader,std::uint64_t carried_rdx) = 0;
    virtual map_decoder_result call_70af8(map_decoder_address destination,map_decoder_address reader) = 0;

    virtual map_decoder_result call_dd58c(map_decoder_address reader,std::uint64_t carried_rdx,map_decoder_address scratch16) = 0;
    virtual map_decoder_result call_d114(map_decoder_address guid,std::uint64_t carried_rdx) = 0;

    virtual map_decoder_result call_3c5fc(map_decoder_address scratch16,std::uint32_t map_id) = 0;

    virtual map_decoder_result call_78932a(map_decoder_address record,std::uint32_t fill,std::uint32_t length) = 0;

    virtual map_decoder_result call_3c6884(map_decoder_address reader,map_decoder_address position,
        std::uint32_t width,std::uint32_t zero,std::uint8_t stack5_low_byte,map_decoder_address bounds) = 0;

    virtual map_decoder_result call_708a4(map_decoder_address reader,std::uint64_t carried_rdx,
        map_decoder_address axis1,map_decoder_address axis2) = 0;
    virtual map_decoder_result call_6fa9c(map_decoder_address properties,map_decoder_address reader) = 0;
};

std::uint8_t decode_map_variant_partial(map_variant_decoder_dependencies& dependencies,
    map_decoder_address variant,map_decoder_address reader,map_decoder_address scratch16);
struct available_decoder_rdx { std::uint64_t bits; };

using decoder_rdx_state=std::variant<available_decoder_rdx,unavailable_list_native_return>;
enum class modern_list_outcome {
    decoder_returned,unsupported_version,compressed_refused,length_refused,
    active_record_refused,unavailable_carrier_refused
};
struct modern_list_result {
    modern_list_outcome outcome;

    std::optional<std::uint8_t> decoder_al;
};

struct modern_list_boundary {
    virtual ~modern_list_boundary()=default;
    virtual uncompressed_list_result call_uncompressed_70af8(
        map_decoder_address destination,map_decoder_address reader)=0;

    virtual map_decoder_result call_dd58c_without_incoming_rdx(
        map_decoder_address reader,map_decoder_address scratch16)=0;
};

modern_list_result decode_map_variant_modern_uncompressed(
    map_variant_decoder_dependencies&,modern_list_boundary&,
    map_decoder_address variant,map_decoder_address reader,
    map_decoder_address scratch16);
}
