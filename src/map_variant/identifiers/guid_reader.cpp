#include "guid_reader.hpp"
#include <bit>

namespace hum::reconstruction::reach {
namespace {
std::uint64_t reverse64(std::uint64_t bits) {
    std::uint64_t result=0;
    for (unsigned i=0;i<8;++i) { result=(result<<8)|(bits&0xffU); bits>>=8; }
    return result;
}
std::uint32_t reverse32(std::uint32_t bits) {
    std::uint32_t result=0;
    for (unsigned i=0;i<4;++i) { result=(result<<8)|(bits&0xffU); bits>>=8; }
    return result;
}
std::uint16_t reverse16(std::uint16_t bits) {
    return static_cast<std::uint16_t>((static_cast<std::uint32_t>(bits)<<8)|(bits>>8));
}
std::uint64_t shift_left(std::uint64_t bits,std::uint32_t count) { return bits<<(count&63U); }
std::uint64_t shift_right(std::uint64_t bits,std::uint32_t count) { return bits>>(count&63U); }
void add32(guid_reader_dependencies& d,guid_reader_address address,std::uint32_t increment) {
    const auto old=d.read32(address);
    d.write32(address,old+increment);
}

std::uint64_t integer(guid_reader_dependencies& d,guid_reader_address reader,
    std::uint32_t width,bool wide,std::uint32_t ordinal) {
    const auto consumed=d.read32(reader+0x30);
    const auto old=d.read64(reader+0x28);
    const auto available=64U-consumed;
    std::uint32_t next_consumed=0;
    std::uint64_t next_window=0;
    std::uint64_t result=0;
    if (std::bit_cast<std::int32_t>(width)<=std::bit_cast<std::int32_t>(available)) {
        add32(d,reader+0x24,width);
        next_consumed=consumed+width;
        result=shift_right(old,64U-width);
        next_window=shift_left(old,width);
        if (wide && width>=64U) { next_window=0; }
    } else {
        auto cursor=d.read64(reader+0x38);
        const auto next_cursor=cursor+8;
        std::uint64_t refill=0;
        std::uint32_t fetched=0;
        if (next_cursor<=d.read64(reader+8)) {
            const auto raw=d.read64(cursor);
            d.write64(reader+0x38,next_cursor);
            refill=reverse64(raw);
            fetched=64;
        } else if (cursor<d.read64(reader+8)) {
            do {
                const auto byte=d.read8(cursor);
                fetched+=8;
                refill=(refill<<8)|byte;
                ++cursor;
                d.write64(reader+0x38,cursor);
            } while (cursor<d.read64(reader+8));
            refill=shift_left(refill,64U-fetched);
        } else {
            fetched=d.empty_refill_private_word(wide ? 0xdd274U : 0xdd10cU,ordinal);
        }
        add32(d,reader+0x20,fetched);

        next_consumed=consumed-64U;
        add32(d,reader+0x24,width);
        next_consumed+=width;
        result=shift_right(old,64U-width)|shift_right(refill,64U-next_consumed);

        if (next_consumed<64U) { next_window=shift_left(refill,next_consumed); }
    }
    d.write64(reader+0x28,next_window);
    d.write32(reader+0x30,next_consumed);
    return wide ? result : static_cast<std::uint32_t>(result);
}
}
guid_reader_continuation read_map_guid_native_projection(guid_reader_dependencies& d,
    guid_reader_address reader,guid_reader_address destination) {
    const auto first=static_cast<std::uint32_t>(integer(d,reader,32,false,0));
    const auto second=static_cast<std::uint16_t>(integer(d,reader,16,false,1));
    const auto third=static_cast<std::uint16_t>(integer(d,reader,16,false,2));
    const auto fourth=integer(d,reader,64,true,3);
    d.write16(destination+4,reverse16(second));
    d.write16(destination+6,reverse16(third));
    d.write32(destination,reverse32(first));
    const auto payload=reverse64(fourth);
    d.write64(destination+8,payload);
    return {0xff000000U,payload,fourth&0xff000000U};
}
}
