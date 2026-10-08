#include "decoder.hpp"
#include "decoder_core.hpp"
#include <stdexcept>

namespace hum::reconstruction::reach {
namespace {
namespace sc=shared_core;
struct numeric_policy {
    static constexpr bool strict=false;
    sc::list_step list(map_variant_decoder_dependencies& d,map_decoder_address destination,
        map_decoder_address reader) {
        return sc::continue_list(available_decoder_rdx{d.call_70af8(destination,reader).rdx_bits});
    }
    decoder_rdx_state guid(map_variant_decoder_dependencies& d,map_decoder_address reader,
        map_decoder_address scratch,const decoder_rdx_state& incoming) {
        return available_decoder_rdx{d.call_dd58c(reader,sc::require_available(incoming),scratch).rdx_bits};
    }
};
struct modern_uncompressed_policy {
    static constexpr bool strict=true;
    modern_list_boundary& boundary;
    sc::list_step list(map_variant_decoder_dependencies&,map_decoder_address destination,
        map_decoder_address reader) {
        const auto list=boundary.call_uncompressed_70af8(destination,reader);
        if(list.outcome==list_profile_outcome::compressed_refused)
            return sc::stop_list(sc::list_stop_reason::compressed_refused);
        if(list.outcome==list_profile_outcome::length_refused)
            return sc::stop_list(sc::list_stop_reason::length_refused);
        return sc::continue_list(list.native_return);
    }
    decoder_rdx_state guid(map_variant_decoder_dependencies&,map_decoder_address reader,
        map_decoder_address scratch,const decoder_rdx_state&) {
        return available_decoder_rdx{boundary.call_dd58c_without_incoming_rdx(reader,scratch).rdx_bits};
    }
};
modern_list_result map_modern(const sc::core_result& result) {
    switch(result.stop) {
    case sc::core_stop::returned:
        return {modern_list_outcome::decoder_returned,result.al};
    case sc::core_stop::unsupported_version:
        return {modern_list_outcome::unsupported_version,std::nullopt};
    case sc::core_stop::active_record_refused:
        return {modern_list_outcome::active_record_refused,std::nullopt};
    case sc::core_stop::list_stopped:
        if(result.reason==sc::list_stop_reason::compressed_refused)
            return {modern_list_outcome::compressed_refused,std::nullopt};
        if(result.reason==sc::list_stop_reason::length_refused)
            return {modern_list_outcome::length_refused,std::nullopt};
        break;
    }
    throw std::logic_error("uncompressed policy produced an unmapped core stop");
}
}
std::uint8_t decode_map_variant_partial(map_variant_decoder_dependencies& d,
    map_decoder_address v,map_decoder_address reader,map_decoder_address scratch) {
    numeric_policy policy;
    const auto result=sc::decode_core(d,policy,v,reader,scratch);
    if(!result.al)throw std::logic_error("standard policy produced profile refusal");
    return *result.al;
}
modern_list_result decode_map_variant_modern_uncompressed(map_variant_decoder_dependencies& d,
    modern_list_boundary& boundary,map_decoder_address v,map_decoder_address reader,map_decoder_address scratch) {
    modern_uncompressed_policy policy{boundary};
    try { return map_modern(sc::decode_core(d,policy,v,reader,scratch)); }
    catch(const sc::unavailable_consumption&) {
        return {modern_list_outcome::unavailable_carrier_refused,std::nullopt};
    }
}
}
