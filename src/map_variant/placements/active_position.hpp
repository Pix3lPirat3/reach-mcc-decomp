#pragma once

#include "../payload/parent.hpp"
#include <array>
#include <cstdint>
#include <optional>
namespace hum::reconstruction::reach {

enum class position_stop_reason : std::uint8_t {
    none, domain_refused, fp_environment_refused, nonfinite_refused,
    home_refused, cookie_tail_refused, excluded_path_refused };
struct position_child_result {
    position_stop_reason reason;
    std::optional<std::array<std::uint32_t,3>> output_bits;
    std::optional<std::uint64_t> rdx_bits;
};

bool valid_position_child_result(const position_child_result&) noexcept;

struct modern_position_boundary {
    virtual ~modern_position_boundary()=default;
    virtual position_child_result call_position_3c6884(map_decoder_address reader,
        map_decoder_address position,std::uint32_t width,std::uint32_t repair,
        std::uint8_t stack5_low_byte,map_decoder_address bounds)=0;
};
enum class active_position_outcome {
    decoder_returned, unsupported_version, list_child_stopped, child_contract_refused,
    position_child_stopped, position_contract_refused, axes_provider_unconnected,
    unavailable_carrier_refused
};
struct position_stop { std::uint32_t slot; position_stop_reason reason; };

struct position_observation {
    std::uint32_t slot; std::array<std::uint32_t,3> output_bits; std::uint64_t rdx_bits;
};
struct active_position_result {
    active_position_outcome outcome;
    std::optional<std::uint8_t> decoder_al;
    std::optional<compressed_list_result> list;
    std::optional<position_stop> stop;
    std::optional<position_observation> position;
};

bool valid_active_position_result(const active_position_result&) noexcept;
active_position_result decode_map_variant_modern_active_position(
    map_variant_decoder_dependencies&,modern_payload_boundary&,modern_position_boundary&,
    map_decoder_address variant,map_decoder_address reader,map_decoder_address scratch16);

}
