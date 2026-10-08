#pragma once

#include "decoder.hpp"
#include <bit>
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <variant>

namespace hum::reconstruction::reach::shared_core {
inline std::int32_t signed32(std::uint32_t bits) { return std::bit_cast<std::int32_t>(bits); }
inline std::int32_t signed16(std::uint16_t bits) { return std::bit_cast<std::int16_t>(bits); }

struct unavailable_consumption {};
inline std::uint64_t require_available(const decoder_rdx_state& state) {
    if(const auto* value=std::get_if<available_decoder_rdx>(&state))return value->bits;
    throw unavailable_consumption{};
}

enum class list_stop_reason { none, compressed_refused, length_refused, child_stopped, child_contract_refused };
enum class core_stop { returned, unsupported_version, list_stopped, active_record_refused };
struct core_result {
    core_stop stop;
    list_stop_reason reason;
    std::optional<std::uint8_t> al;
};

struct list_step {
    std::optional<decoder_rdx_state> rdx;
    list_stop_reason reason;
};
inline list_step continue_list(decoder_rdx_state state) { return {state,list_stop_reason::none}; }
inline list_step stop_list(list_stop_reason reason) { return {std::nullopt,reason}; }
inline core_result returned(std::uint8_t al) { return {core_stop::returned,list_stop_reason::none,al}; }
inline core_result stopped(core_stop stop,list_stop_reason reason=list_stop_reason::none) {
    return {stop,reason,std::nullopt};
}

template<class Policy>
core_result decode_core(map_variant_decoder_dependencies& d,Policy& policy,
    map_decoder_address v,map_decoder_address reader,map_decoder_address scratch) {
    decoder_rdx_state rdx=available_decoder_rdx{d.call_103638(reader,v).rdx_bits};
    const auto integer = [&](std::uint32_t width) {
        const auto result = d.call_dd10c(reader,width);
        rdx = available_decoder_rdx{result.rdx_bits};
        return static_cast<std::uint32_t>(result.rax_bits);
    };
    const auto boolean = [&]() {
        const auto result = d.call_54214(reader,require_available(rdx));
        rdx = available_decoder_rdx{result.rdx_bits};
        return static_cast<std::uint8_t>(result.rax_bits);
    };
    const auto version = static_cast<std::uint16_t>(integer(8));
    d.write16(v+0x2b0,version);
    if constexpr(Policy::strict) { if(signed16(version)<32)return stopped(core_stop::unsupported_version); }
    if (signed16(version)<31) { return returned(0); }
    d.write32(v+0x2ec,integer(32));
    d.write32(v+0x2f0,integer(32));
    const auto count = static_cast<std::uint16_t>(integer(9));
    d.write16(v+0x2b2,count);
    std::uint8_t accepted = static_cast<std::uint8_t>(count<=256);
    d.write32(v+0x2b4,integer(32));
    d.write8(v+0x2e9,boolean());
    d.write8(v+0x2ea,boolean());
    for (std::uint32_t i=0;i<6;++i) { d.write32(v+0x2c8+i*4,integer(32)); }
    d.write32(v+0x2e0,integer(32));
    d.write32(v+0x2e4,integer(32));
    d.write32(v+0x14f8,0);
    for (std::uint32_t i=0;i<256;++i) { d.write16(v+0x12f8+i*2,0xffff); }
    d.write32(v+0x12f4,0);
    auto length = integer(9);
    d.write32(v+0x14f8,length);
    if (signed32(length)>0) {
        std::uint32_t index=0;
        auto cursor=v+0x12f8;
        do {
            if (boolean()!=0) { d.write16(cursor,static_cast<std::uint16_t>(integer(12))); }
            length=d.read32(v+0x14f8);
            ++index;
            cursor+=2;
        } while (signed32(index)<signed32(length));
        if (signed32(length)>0) {
            const auto step=policy.list(d,v+0x2f4,reader);
            if(!step.rdx) {
                if(step.reason==list_stop_reason::none)throw std::logic_error("list stop without reason");
                return stopped(core_stop::list_stopped,step.reason);
            }
            rdx=*step.rdx;
        }
    }
    if (accepted==0) { return returned(0); }
    const auto guid_version=d.read16(v+0x2b0);
    if constexpr(Policy::strict) { if(signed16(guid_version)<32)return stopped(core_stop::unsupported_version); }
    if (signed16(guid_version)>=32) {

        d.write32(scratch,0);
        d.write64(scratch+6,0);
        d.write16(scratch+14,0);
        d.write16(scratch+4,0);
        rdx=policy.guid(d,reader,scratch,rdx);
        const auto guid=d.read128(scratch);
        d.write128(v+0x2b8,guid);
        const auto result=d.call_d114(v+0x2b8,require_available(rdx));
        rdx=available_decoder_rdx{result.rdx_bits};
        accepted=static_cast<std::uint8_t>(result.rax_bits);
    }
    if (accepted==0) { return returned(0); }
    const auto legacy_version=d.read16(v+0x2b0);
    if constexpr(Policy::strict) { if(signed16(legacy_version)<32)return stopped(core_stop::unsupported_version); }
    if (signed16(legacy_version)<32) {
        const auto result=d.call_3c5fc(scratch,d.read32(v+0x2b4));
        rdx=available_decoder_rdx{result.rdx_bits};
        const auto guid=d.read128(result.rax_bits);
        d.write128(v+0x2b8,guid);
        const auto validation=d.call_d114(v+0x2b8,require_available(rdx));
        rdx=available_decoder_rdx{validation.rdx_bits};
        if (static_cast<std::uint8_t>(validation.rax_bits)!=0 && d.read16(v+0x2b0)!=32) {
            d.write16(v+0x2b0,32);
        }
    }
    auto record=v+0x14fc;
    for (std::uint32_t slot=0;slot<651;++slot,record+=0x4c) {
        rdx=available_decoder_rdx{d.call_78932a(record,0,0x4c).rdx_bits};
        d.write16(record+2,0xffff);
        d.write32(record+4,0xffffffff);
        d.write16(record+0x2c,0xffff);
        d.write8(record+0x4a,0xff);
        d.write16(record+0x44,0xffff);
        d.write8(record+0x47,8);
        if (boolean()!=0) {

            if constexpr(requires{Policy::active_scalar_prefix;}) {
                static_assert(Policy::strict && Policy::active_scalar_prefix);
                d.write16(record,static_cast<std::uint16_t>(integer(2)));
                const auto quota=boolean()!=0 ? 0xffffffffU : integer(8);
                d.write16(record+2,static_cast<std::uint16_t>(quota));
                const auto type=boolean()!=0 ? 0xffffffffU : integer(5);
                d.write8(record+0x2e,static_cast<std::uint8_t>(type));

                return policy.stop_before_position(slot);
            }
            if constexpr(Policy::strict)return stopped(core_stop::active_record_refused);
            d.write16(record,static_cast<std::uint16_t>(integer(2)));
            const auto quota=boolean()!=0 ? 0xffffffffU : integer(8);
            d.write16(record+2,static_cast<std::uint16_t>(quota));
            const auto type=boolean()!=0 ? 0xffffffffU : integer(5);
            d.write8(record+0x2e,static_cast<std::uint8_t>(type));
            rdx=available_decoder_rdx{d.call_3c6884(reader,record+8,21,0,1,v+0x2c8).rdx_bits};
            rdx=available_decoder_rdx{d.call_708a4(reader,require_available(rdx),record+0x14,record+0x20).rdx_bits};
            const auto relative=static_cast<std::uint16_t>(integer(10)-1U);
            d.write16(record+0x2c,relative);
            rdx=available_decoder_rdx{d.call_6fa9c(record+0x30,reader).rdx_bits};
        }
    }
    for (std::uint32_t i=0;i<256;++i) {
        const auto quota=v+0xd640+i*3;
        if (signed32(i)<signed16(d.read16(v+0x2b2))) {
            d.write8(quota,static_cast<std::uint8_t>(integer(8)));
            d.write8(quota+1,static_cast<std::uint8_t>(integer(8)));
            d.write8(quota+2,static_cast<std::uint8_t>(integer(8)));
        } else {

            const auto old=d.read16(quota);
            d.write16(quota,static_cast<std::uint16_t>(old & 0U));
            d.write8(quota+2,0);
        }
    }
    return returned(accepted);
}
}
