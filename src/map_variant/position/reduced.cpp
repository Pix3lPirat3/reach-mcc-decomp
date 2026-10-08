#include "reduced.hpp"
#include "decode_core.hpp"
#include "../records/presence_core.hpp"
#include "../../security/cookie_core.hpp"
#include "../../math/quantization/widths.hpp"
#include "../../math/scalar/ceilf_adapter.hpp"
#include <bit>
#include <immintrin.h>
#include <limits>
#include <stdexcept>
namespace hum::reconstruction::reach::position_reduced {
namespace {
using lanes=recon1550::lanes;
struct refused {outcome status;};
struct word {
    std::optional<std::uint64_t> bits;
    operator std::uint64_t()const {if(!bits)throw refused{outcome::excluded_path_refused};return *bits;}
    word& operator=(std::uint64_t value){bits=value;return *this;}
    word& operator+=(std::uint64_t value){bits=static_cast<std::uint64_t>(*this)+value;return *this;}
    word& operator^=(std::uint64_t value){bits=static_cast<std::uint64_t>(*this)^value;return *this;}
    word& operator<<=(std::uint64_t count){bits=static_cast<std::uint64_t>(*this)<<count;return *this;}
    word& operator>>=(std::uint64_t count){bits=static_cast<std::uint64_t>(*this)>>count;return *this;}
    word& operator|=(std::uint64_t value){bits=static_cast<std::uint64_t>(*this)|value;return *this;}
    word& operator++(){return operator+=(std::uint64_t{1});}
};
struct lane_slot {
    std::optional<lanes> bits;
    lane_slot& operator=(const lanes& value){bits=value;return *this;}
    operator const lanes&()const {if(!bits)throw refused{outcome::excluded_path_refused};return *bits;}
    std::uint32_t& operator[](std::size_t at){if(!bits)throw refused{outcome::excluded_path_refused};return (*bits)[at];}
};
struct reduced_state {
    word rax,rcx,rdx,r8,r9,r10,r11;
    std::array<lane_slot,6> xmm;
};
bool finite(std::uint32_t bits){return (bits&0x7f800000U)!=0x7f800000U;}
void environment(){if((_mm_getcsr()&0xffc0U)!=0x1f80U)throw refused{outcome::fp_refused};}
__m128 operand(std::uint32_t bits){return _mm_castsi128_ps(_mm_cvtsi32_si128(std::bit_cast<std::int32_t>(bits)));}
std::uint32_t low(__m128 value){return static_cast<std::uint32_t>(_mm_cvtsi128_si32(_mm_castps_si128(value)));}
bool valid(extent e){return e.size&&e.begin<=std::numeric_limits<address>::max()-e.size;}
bool overlaps(extent a,extent b){return a.begin<b.begin+b.size&&b.begin<a.begin+a.size;}
bool contains(extent e,address at,address size){return at>=e.begin&&size<=e.size&&at-e.begin<=e.size-size;}
struct bridge final:memory624,native_bitstream_reader_memory,native_bitstream_reader_private_input {
    memory& ram;const admission& a;address reader,output;extent frame;
    std::array<std::optional<std::uint32_t>,3> captures;
    std::optional<std::uint32_t> bound_upper;
    bool stream_child=false;
    bridge(memory& m,const admission& scope,address r,address o):ram(m),a(scope),reader(r),output(o),frame{scope.frame-0x50,0xc0}{}
    void guard(address at,address size){
        environment();if(at>std::numeric_limits<address>::max()-size)throw refused{outcome::domain_refused};
        if(stream_child&&(at<reader||at-reader>=0x40)){
            const extent access{at,size};
            for(const auto forbidden:std::array<extent,7>{{frame,{output,12},{a.bounds,24},{a.module+0xafa010,8},{a.module+0xa8ad74,4},{a.module+0xa8aa74,4},{a.module+0xa8a9b8,4}}})
                if(overlaps(access,forbidden))throw refused{outcome::domain_refused};
        }
        if(contains(frame,at,size))return;
        for(const auto e:a.initialized_guest)if(contains(e,at,size))return;
        throw refused{outcome::domain_refused};
    }
    std::uint8_t read8(address at)override{guard(at,1);const auto value=ram.read8(at);environment();return value;}
    std::uint16_t read16(address at)override{guard(at,2);const auto value=ram.read16(at);environment();return value;}
    std::uint32_t read32(address at)override{
        guard(at,4);const auto value=ram.read32(at);environment();
        if(stream_child&&at==reader+0x30&&value>64U)throw refused{outcome::domain_refused};
        if((at>=a.bounds&&at-a.bounds<24)||(at==a.module+0xa8ad74)||(at==a.module+0xa8aa74)||(at==a.module+0xa8a9b8)){
            if(!finite(value))throw refused{outcome::nonfinite_refused};
        }

        if(at>=a.bounds&&at-a.bounds<24){
            if((at-a.bounds)%8==4)bound_upper=value;
            else if((at-a.bounds)%8==0&&bound_upper){
                if(!finite(low(_mm_sub_ss(operand(*bound_upper),operand(value)))))throw refused{outcome::nonfinite_refused};
                bound_upper.reset();
            }
        }
        return value;
    }
    address read64(address at)override{
        guard(at,8);const auto value=ram.read64(at);environment();
        if(at==a.frame+0x68&&value!=a.bounds){throw refused{outcome::domain_refused};}
        if(stream_child&&at==reader+0x38){
            if(value==std::numeric_limits<address>::max())throw refused{outcome::domain_refused};
            const extent point{value,1};
            for(const auto forbidden:std::array<extent,8>{{frame,{reader,0x40},{output,12},{a.bounds,24},{a.module+0xafa010,8},{a.module+0xa8ad74,4},{a.module+0xa8aa74,4},{a.module+0xa8a9b8,4}}})
                if(overlaps(point,forbidden))throw refused{outcome::domain_refused};
        }
        return value;
    }
    void write8(address at,std::uint8_t value)override{guard(at,1);ram.write8(at,value);environment();}
    void write32(address at,std::uint32_t value)override{
        guard(at,4);ram.write32(at,value);environment();
        if(at>=output&&at-output<12&&(at-output)%4==0)captures[static_cast<std::size_t>((at-output)/4)]=value;
    }
    void write64(address at,address value)override{guard(at,8);ram.write64(at,value);environment();}
    std::uint32_t empty_refill_caller_home_word()override{throw refused{outcome::scalar_home_refused};}
    std::uint32_t sse32(recon1550::scalar_sse operation,std::uint32_t x,std::uint32_t y){
        environment();if(!finite(x)||!finite(y))throw refused{outcome::nonfinite_refused};__m128 value;
        switch(operation){
            case recon1550::scalar_sse::sub:value=_mm_sub_ss(operand(x),operand(y));break;
            case recon1550::scalar_sse::div:value=_mm_div_ss(operand(x),operand(y));break;
            case recon1550::scalar_sse::mul:value=_mm_mul_ss(operand(x),operand(y));break;
            case recon1550::scalar_sse::add:value=_mm_add_ss(operand(x),operand(y));break;
            default:throw refused{outcome::excluded_path_refused};
        }
        const auto bits=low(value);if(!finite(bits))throw refused{outcome::nonfinite_refused};return bits;
    }
    lanes cvtdq2ps(const lanes& input){
        environment();const auto value=_mm_cvtepi32_ps(_mm_loadu_si128(reinterpret_cast<const __m128i*>(input.data())));lanes out;
        _mm_storeu_si128(reinterpret_cast<__m128i*>(out.data()),_mm_castps_si128(value));return out;
    }
    reduced_state call_54214(reduced_state state){stream_child=true;const auto out=recon1703::flag_shared_detail::read_flag_core(*this,state);stream_child=false;return out;}
    reduced_state call_dd10c(reduced_state state){
        stream_child=true;const auto out=read_native_bitstream_integer(*this,static_cast<address>(state.rcx),static_cast<address>(state.rdx),*this);stream_child=false;
        state.rax=out.rax_bits;state.rdx=out.rdx_bits;state.r11=out.r11_bits;
        state.rcx.bits.reset();state.r8.bits.reset();state.r9.bits.reset();state.r10.bits.reset();return state;
    }
    reduced_state call_3c9a68(reduced_state state){
        environment();recon1008::FiniteCeilfAdapter imported;
        const auto out=quantized_widths624(*this,imported,{static_cast<std::uint32_t>(state.rcx),state.rdx,state.r9,a.module+0xa8aa74,a.module+0xa8a9b8,a.module});
        environment();if(out.cookie!=security_cookie_disposition::normal_return)throw refused{outcome::cookie_tail_refused};
        return reduced_state{};
    }
    reduced_state call_3c9a0c(reduced_state){throw refused{outcome::excluded_path_refused};}
    reduced_state call_787e00(reduced_state state){
        const auto out=cookie_shared_detail::check_cookie(*this,a.module,state);
        if(out.disposition!=security_cookie_disposition::normal_return){throw refused{outcome::cookie_tail_refused};}
        return out.registers;
    }
};
void validate(const admission& a,address reader,address output){
    environment();if(!a.bounds||a.frame<0x70||a.module>std::numeric_limits<address>::max()-0xafa018)throw refused{outcome::domain_refused};
    const extent frame{a.frame-0x50,0xc0};if(!valid(frame)||a.initialized_guest.empty())throw refused{outcome::domain_refused};
    for(std::size_t i=0;i<a.initialized_guest.size();++i){const auto e=a.initialized_guest[i];if(!valid(e)||overlaps(e,frame))throw refused{outcome::domain_refused};
        for(std::size_t j=0;j<i;++j)if(overlaps(e,a.initialized_guest[j]))throw refused{outcome::domain_refused};}
    for(const auto required:std::array<extent,3>{{{reader,0x40},{output,12},{a.bounds,24}}}){
        bool found=false;for(const auto e:a.initialized_guest)found=found||contains(e,required.begin,required.size);if(!found)throw refused{outcome::domain_refused};
    }
    if(overlaps({reader,0x40},{output,12})||overlaps({reader,0x40},{a.bounds,24})||overlaps({output,12},{a.bounds,24}))throw refused{outcome::domain_refused};
}
}
result decode(memory& ram,const admission& a,address reader,address output){
    try{
        validate(a,reader,output);bridge actual(ram,a,reader,output);reduced_state entry;
        entry.rcx=reader;entry.rdx=output;entry.r8=21;entry.r9=0;
        const auto out=recon1550::position_shared_detail::decode_core(actual,a.module,a.frame,entry);
        if(static_cast<address>(out.rdx)!=12)throw refused{outcome::excluded_path_refused};
        std::array<std::uint32_t,3> bits;
        for(std::size_t i=0;i<3;++i){if(!actual.captures[i])throw refused{outcome::excluded_path_refused};bits[i]=*actual.captures[i];}
        return {outcome::completed,bits,static_cast<address>(out.rdx)};
    }catch(const refused& refusal){return {refusal.status,std::nullopt,std::nullopt};}
    catch(const std::domain_error&){return {outcome::nonfinite_refused,std::nullopt,std::nullopt};}
}
}
