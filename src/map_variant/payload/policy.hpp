#pragma once

#include "parent.hpp"
#include "../decoder_core.hpp"
namespace hum::reconstruction::reach::payload_detail {
namespace sc=shared_core;
enum class verdict { proceed, stopped, contract_refused };

inline verdict classify(const compressed_list_result& r) noexcept {
    if(r.parent_decoder_al.has_value())return verdict::contract_refused;
    switch(r.outcome) {
    case compressed_list_outcome::uncompressed_projection_complete:
    case compressed_list_outcome::library_payload_projection_complete:
        return r.stop==compressed_list_stop::none?verdict::proceed:verdict::contract_refused;
    case compressed_list_outcome::source_domain_stop:
        switch(r.stop) {
        case compressed_list_stop::length_after_flag_and_reload:
        case compressed_list_stop::m_after_second_integer:
        case compressed_list_stop::h_after_raw_snapshot:
            return verdict::stopped;
        default: return verdict::contract_refused;
        }
    case compressed_list_outcome::unsupported_library_result:
        return r.stop==compressed_list_stop::library_after_owned_call?verdict::stopped:verdict::contract_refused;
    }
    return verdict::contract_refused;
}
struct payload_policy {
    static constexpr bool strict=true;
    modern_payload_boundary& boundary;
    std::optional<compressed_list_result>& observed;
    sc::list_step list(map_variant_decoder_dependencies&,map_decoder_address destination,
        map_decoder_address reader) {
        observed=boundary.call_payload_70af8(destination,reader);
        switch(classify(*observed)) {
        case verdict::proceed: return sc::continue_list(observed->native_return);
        case verdict::stopped: return sc::stop_list(sc::list_stop_reason::child_stopped);
        case verdict::contract_refused: break;
        }
        return sc::stop_list(sc::list_stop_reason::child_contract_refused);
    }
    decoder_rdx_state guid(map_variant_decoder_dependencies&,map_decoder_address reader,
        map_decoder_address scratch,const decoder_rdx_state&) {

        return available_decoder_rdx{boundary.call_dd58c_without_incoming_rdx(reader,scratch).rdx_bits};
    }
};
}
