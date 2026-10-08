#pragma once
#include "qword_reader.hpp"

namespace hum::reconstruction::reach {
struct raw_data_reader_memory : native_bitstream_reader_memory {
    virtual void write8(native_bitstream_reader_address,std::uint8_t) = 0;
};
struct raw_data_reader_result {
    std::uint64_t rax_bits,rdx_bits;
    bool operator==(const raw_data_reader_result&) const = default;
};

struct raw_data_reader_observer {
    virtual ~raw_data_reader_observer() = default;
    virtual void qword_requested(native_bitstream_reader_address,std::uint64_t incoming_rdx) = 0;
    virtual void qword_completed(const native_bitstream_reader_continuation&) = 0;
};

raw_data_reader_result read_raw_data_dcf28(raw_data_reader_memory&,
    native_bitstream_reader_address reader,native_bitstream_reader_address destination,
    std::uint64_t incoming_r8,std::uint64_t incoming_rax,
    native_bitstream_reader_private_input&,raw_data_reader_observer* = nullptr);
}
