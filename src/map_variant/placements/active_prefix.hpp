#pragma once

#include "../payload/parent.hpp"
namespace hum::reconstruction::reach {
enum class active_prefix_outcome {
    decoder_returned, unsupported_version, list_child_stopped,
    child_contract_refused, position_provider_unconnected, unavailable_carrier_refused
};
enum class active_prefix_reason : std::uint8_t { provider_unconnected };
struct active_prefix_stop { std::uint32_t slot; active_prefix_reason reason; };
struct active_prefix_result {
    active_prefix_outcome outcome;
    std::optional<std::uint8_t> decoder_al;
    std::optional<compressed_list_result> list;
    std::optional<active_prefix_stop> prefix;
};

bool valid_active_prefix_result(const active_prefix_result&) noexcept;
active_prefix_result decode_map_variant_modern_active_prefix(
    map_variant_decoder_dependencies&,modern_payload_boundary&,
    map_decoder_address variant,map_decoder_address reader,map_decoder_address scratch16);

}
