#pragma once
#include "../../bitstream/raw_data_reader.hpp"
#include "../records/presence_reader.hpp"
#include <optional>

namespace hum::reconstruction::reach {
struct uncompressed_list_memory : raw_data_reader_memory,recon1703::Memory {
    virtual std::uint8_t read8(std::uint64_t) override = 0;
    virtual std::uint32_t read32(std::uint64_t) override = 0;
    virtual std::uint64_t read64(std::uint64_t) override = 0;
    virtual void write32(std::uint64_t,std::uint32_t) override = 0;
    virtual void write64(std::uint64_t,std::uint64_t) override = 0;
};
enum class list_profile_outcome { uncompressed_complete,compressed_refused,length_refused };

struct unavailable_list_native_return {
    bool operator==(const unavailable_list_native_return&) const = default;
};
struct uncompressed_list_result {
    list_profile_outcome outcome;
    std::uint32_t published_length;

    std::optional<raw_data_reader_result> payload_observation;
    unavailable_list_native_return native_return;
    bool operator==(const uncompressed_list_result&) const = default;
};
struct uncompressed_list_observer : raw_data_reader_observer {
    virtual void integer_requested(std::uint64_t,std::uint32_t) = 0;
    virtual void integer_completed(const native_bitstream_reader_continuation&) = 0;
    virtual void flag_requested(std::uint64_t,std::uint64_t) = 0;
    virtual void flag_completed(const recon1703::Registers&) = 0;
    virtual void raw_requested(std::uint64_t,std::uint64_t,std::uint32_t,std::uint64_t) = 0;
    virtual void raw_completed(const raw_data_reader_result&) = 0;
};

uncompressed_list_result decode_uncompressed_list_70af8(uncompressed_list_memory&,
    std::uint64_t destination,std::uint64_t reader,
    native_bitstream_reader_private_input& integer_home,
    native_bitstream_reader_private_input& raw_home,
    recon1703::Registers logical_flag_seed,
    uncompressed_list_observer* = nullptr);
}
