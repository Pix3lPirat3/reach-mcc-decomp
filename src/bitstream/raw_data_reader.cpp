#include "raw_data_reader.hpp"

namespace hum::reconstruction::reach {
namespace {
std::uint64_t reverse64(std::uint64_t x) {
    std::uint64_t out=0;
    for(unsigned i=0;i<8;++i){out=(out<<8)|(x&255U);x>>=8;}
    return out;
}
}
raw_data_reader_result read_raw_data_dcf28(raw_data_reader_memory& memory,
    native_bitstream_reader_address reader,native_bitstream_reader_address destination,
    std::uint64_t incoming_r8,std::uint64_t incoming_rax,
    native_bitstream_reader_private_input& home,raw_data_reader_observer* observer) {
    std::uint32_t remaining=static_cast<std::uint32_t>(incoming_r8);
    raw_data_reader_result result{incoming_rax,destination};
    const auto qword=[&](std::uint32_t width) {
        const std::uint64_t outgoing_rdx=width;
        if(observer)observer->qword_requested(reader,outgoing_rdx);
        const auto child=read_native_bitstream_qword(memory,reader,outgoing_rdx,home);
        if(observer)observer->qword_completed(child);
        return child;
    };
    while(remaining>=64U) {
        const auto child=qword(64);
        result={reverse64(child.rax_bits),child.rdx_bits};
        memory.write64(destination,result.rax_bits);
        remaining-=64U;destination+=8U;
    }
    if(remaining!=0) {
        const auto child=qword(remaining);
        result={child.rax_bits,child.rdx_bits};
        std::uint64_t shifted=child.rax_bits<<((64U-remaining)&63U);
        if(remaining>=8U) {
            result.rdx_bits=remaining>>3;
            remaining-=static_cast<std::uint32_t>(result.rdx_bits)*8U;
            do {
                result.rax_bits=shifted>>56;
                shifted<<=8;
                memory.write8(destination,static_cast<std::uint8_t>(result.rax_bits));
                ++destination;--result.rdx_bits;
            }while(result.rdx_bits!=0);
        }
        if(remaining!=0)memory.write8(destination,static_cast<std::uint8_t>(shifted>>56));
    }
    return result;
}
}
