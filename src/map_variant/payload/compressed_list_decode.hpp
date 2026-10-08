#pragma once
#include "uncompressed_list_decode.hpp"
#include "payload_decoder.hpp"
#include <optional>

namespace hum::reconstruction::reach {
enum class compressed_list_phase { supported_prefix, owned_snapshot, owned_library, owned_commit };
enum class compressed_list_outcome { uncompressed_projection_complete, library_payload_projection_complete,
                                     source_domain_stop, unsupported_library_result };
enum class compressed_list_stop { none, length_after_flag_and_reload, m_after_second_integer,
                                 h_after_raw_snapshot, library_after_owned_call };
struct compressed_list_profile {
    std::uint64_t allocation_budget;
    hum::historical_payload::AllocatorPolicy allocator_policy;
};
struct compressed_list_result {
    compressed_list_outcome outcome;
    compressed_list_stop stop;
    std::uint32_t initial_l;
    std::optional<std::uint32_t> fresh_l, m, h;
    std::optional<raw_data_reader_result> raw_observation;
    std::optional<hum::historical_payload::Result> library_observation;
    std::uint32_t committed_payload_bytes;
    unavailable_list_native_return native_return;

    std::optional<std::uint8_t> parent_decoder_al;
};
struct compressed_list_observer : uncompressed_list_observer {
    virtual void phase_changed(compressed_list_phase) = 0;
    virtual void library_requested(std::uint32_t m,std::uint32_t h,std::uint32_t l) = 0;
    virtual void library_completed(const hum::historical_payload::Result&) = 0;
    virtual void commit_completed(std::uint32_t) = 0;
};

bool qualified_compressed_payload(const hum::historical_payload::Result&,
    std::uint32_t m,std::uint32_t h,std::uint32_t l,std::uint64_t budget) noexcept;

compressed_list_result decode_owned_compressed_list(uncompressed_list_memory&,
    std::uint64_t destination,std::uint64_t reader,std::uint64_t temporary,
    native_bitstream_reader_private_input& length_home,
    native_bitstream_reader_private_input& compressed_count_home,
    native_bitstream_reader_private_input& raw_home,
    recon1703::Registers logical_flag_seed,const compressed_list_profile&,
    compressed_list_observer* = nullptr);
}
