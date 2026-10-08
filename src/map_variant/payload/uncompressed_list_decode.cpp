#include "uncompressed_list_decode.hpp"

namespace hum::reconstruction::reach {
uncompressed_list_result decode_uncompressed_list_70af8(uncompressed_list_memory& memory,
    std::uint64_t destination,std::uint64_t reader,
    native_bitstream_reader_private_input& integer_home,
    native_bitstream_reader_private_input& raw_home,
    recon1703::Registers seed,uncompressed_list_observer* observer) {
    if(observer)observer->integer_requested(reader,13);
    const auto integer=read_native_bitstream_integer(memory,reader,13,integer_home);
    if(observer)observer->integer_completed(integer);
    const auto published=static_cast<std::uint32_t>(integer.rax_bits);
    memory.write32(destination+0x1000,published);
    seed.rcx=reader;seed.rdx=integer.rdx_bits;seed.rax=integer.rax_bits;seed.r11=integer.r11_bits;
    if(observer)observer->flag_requested(reader,seed.rdx);
    const auto flag=recon1703::read_flag(memory,seed);
    if(observer)observer->flag_completed(flag);
    if(static_cast<std::uint8_t>(flag.rax)!=0)
        return {list_profile_outcome::compressed_refused,published,std::nullopt,{}};
    const auto length=memory.read32(destination+0x1000);
    if(length>4096U)
        return {list_profile_outcome::length_refused,published,std::nullopt,{}};
    const std::uint32_t bits=length<<3;
    if(observer)observer->raw_requested(reader,destination,bits,flag.rax);
    const auto payload=read_raw_data_dcf28(memory,reader,destination,bits,flag.rax,raw_home,observer);
    if(observer)observer->raw_completed(payload);
    return {list_profile_outcome::uncompressed_complete,published,payload,{}};
}
}
