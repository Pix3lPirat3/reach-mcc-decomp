#pragma once

#include "../decoder.hpp"
#include "compressed_list_decode.hpp"
#include <optional>

namespace hum::reconstruction::reach {
enum class modern_payload_outcome {
    decoder_returned,
    unsupported_version,
    list_child_stopped,
    child_contract_refused,
    active_record_refused,
    unavailable_carrier_refused
};
struct modern_payload_result {
    modern_payload_outcome outcome;

    std::optional<std::uint8_t> decoder_al;

    std::optional<compressed_list_result> list;
};

struct modern_payload_boundary {
    virtual ~modern_payload_boundary()=default;

    virtual compressed_list_result call_payload_70af8(
        map_decoder_address destination,map_decoder_address reader)=0;

    virtual map_decoder_result call_dd58c_without_incoming_rdx(
        map_decoder_address reader,map_decoder_address scratch16)=0;
};

modern_payload_result decode_map_variant_modern_payload(
    map_variant_decoder_dependencies&,modern_payload_boundary&,
    map_decoder_address variant,map_decoder_address reader,map_decoder_address scratch16);
}
