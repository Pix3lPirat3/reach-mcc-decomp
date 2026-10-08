#pragma once
#include "kernel.hpp"
#include <bit>
#include <stdexcept>
#include <emmintrin.h>
#include <xmmintrin.h>

namespace hum::reconstruction::reach::local1856c::detail {
struct changed_fp_environment {};
struct unavailable_input {};
struct selected_domain_refused {};
struct lane {
    vector_bits storage{};
    unsigned defined=0;
    bool coefficient=false;
    static lane full(vector_bits bits) { return {bits,15,false}; }
    static lane scalar(std::uint32_t bits) { return {{bits,0,0,0},15,false}; }
    static lane low(std::uint32_t bits) { return {{bits,0,0,0},1,true}; }
    std::uint32_t consume() const {
        if (!(defined&1U)) throw unavailable_input{};
        return storage[0];
    }
    vector_bits complete() const {
        if (defined!=15) throw unavailable_input{};
        return storage;
    }
};
inline bool normal_or_zero(std::uint32_t bits) {
    const auto magnitude=bits&0x7fffffffU;
    return magnitude==0 || (magnitude>=0x00800000U && magnitude<0x7f800000U);
}
enum class op { multiply,add,subtract };
inline lane arithmetic(lane left,const lane& right,op operation,bool selected) {
    const auto a=left.consume(),b=right.consume();
    if (selected && (!normal_or_zero(a)||!normal_or_zero(b))) throw selected_domain_refused{};
    const auto coefficient_ok=[](const lane& value,std::uint32_t raw) {
        const auto magnitude=raw&0x7fffffffU;
        return !value.coefficient || magnitude==0 || (magnitude>=0x30800000U && magnitude<=0x3f800000U);
    };
    if (selected && (!coefficient_ok(left,a)||!coefficient_ok(right,b))) throw selected_domain_refused{};
    auto x=_mm_castsi128_ps(_mm_cvtsi32_si128(std::bit_cast<std::int32_t>(a)));
    const auto y=_mm_castsi128_ps(_mm_cvtsi32_si128(std::bit_cast<std::int32_t>(b)));
    if (operation==op::multiply) x=_mm_mul_ss(x,y);
    else if (operation==op::add) x=_mm_add_ss(x,y);
    else x=_mm_sub_ss(x,y);
    const auto bits=std::bit_cast<std::uint32_t>(_mm_cvtsi128_si32(_mm_castps_si128(x)));
    if (selected && (!normal_or_zero(bits)||(bits&0x7fffffffU)>0x43000000U)) throw selected_domain_refused{};
    left.storage[0]=bits; left.defined|=1U; left.coefficient=false;
    return left;
}
inline void require_cartesian(const lane& ax,const lane& ay,const lane& az,
                              const lane& bx,const lane& by,const lane& bz) {
    const auto valid=[](const lane& x,const lane& y,const lane& z) {
        unsigned count=0;
        for (const auto* value:{&x,&y,&z}) {
            const auto magnitude=value->consume()&0x7fffffffU;
            if (magnitude==0x3f800000U) ++count;
            else if (magnitude!=0) return false;
        }
        return count==1;
    };
    if (!valid(ax,ay,az)||!valid(bx,by,bz)) throw selected_domain_refused{};
}
class accesses {
public:
    accesses(memory& ram,std::uint32_t controls,bool selected,address global)
        :ram_(ram),controls_(controls),selected_(selected),global_(global) {}
    lane read(address at) {
        check();const auto value=ram_.read32(at);check();
        if (selected_ && at==global_ && value!=0x3f800000U) throw selected_domain_refused{};
        return lane::scalar(value);
    }
    void write(address at,const lane& value) {
        check();ram_.write32(at,value.consume());check();
    }
private:
    void check() const {
        if ((_mm_getcsr()&0xffc0U)!=controls_) throw changed_fp_environment{};
    }
    memory& ram_;std::uint32_t controls_;bool selected_;address global_;
};
inline std::array<lane,6> execute(memory& ram,address module,address destination,address reference,
    const std::array<lane,6>& incoming,const std::array<lane,10>& original,
    bool selected,std::uint32_t controls) {
    accesses io(ram,controls,selected,module+0xa8af18U);
    auto x0=incoming[0],x1=incoming[1],x2=incoming[2],x3=incoming[3],x4=incoming[4],x5=incoming[5];
    auto x6=original[0],x7=original[1],x8=original[2],x9=original[3],x10=original[4],x11=original[5],x12=original[6];
        x4 = io.read(reference + 8U);
        x5 = io.read(destination + 8U);
        x1 = x4;
        x6 = io.read(reference + 4U);
        x0 = x6;
        x8 = io.read(reference);
        x7 = x8;
        x9 = io.read(destination + 4U);
        x0 = arithmetic(x0, x9, op::multiply, selected);
        x10 = x3;
        x11 = io.read(destination);
        if (selected) require_cartesian(x11, x9, x5, x8, x6, x4);
        x7 = arithmetic(x7, x11, op::multiply, selected);
        x1 = arithmetic(x1, x5, op::multiply, selected);
        x7 = arithmetic(x7, x0, op::add, selected);
        x0 = io.read(module + 0xa8af18U);
        x12 = x2;
        x0 = arithmetic(x0, x10, op::subtract, selected);
        x2 = x8;
        x7 = arithmetic(x7, x1, op::add, selected);
        x1 = x4;
        x1 = arithmetic(x1, x9, op::multiply, selected);
        x7 = arithmetic(x7, x0, op::multiply, selected);
        x0 = x11;
        x0 = arithmetic(x0, x10, op::multiply, selected);
        x2 = arithmetic(x2, x7, op::multiply, selected);
        x3 = x7;
        x2 = arithmetic(x2, x0, op::add, selected);
        x0 = x5;
        x0 = arithmetic(x0, x6, op::multiply, selected);
        x1 = arithmetic(x1, x0, op::subtract, selected);
        x0 = x9;
        x0 = arithmetic(x0, x10, op::multiply, selected);
        x1 = arithmetic(x1, x12, op::multiply, selected);
        x2 = arithmetic(x2, x1, op::subtract, selected);
        x1 = x8;
        x1 = arithmetic(x1, x5, op::multiply, selected);
        x8 = arithmetic(x8, x9, op::multiply, selected);
        x9 = original[3];
        io.write(destination, x2);
        x3 = arithmetic(x3, io.read(reference + 4U), op::multiply, selected);
        x5 = arithmetic(x5, x10, op::multiply, selected);
        x10 = original[4];
        x3 = arithmetic(x3, x0, op::add, selected);
        x0 = x11;
        x11 = arithmetic(x11, x6, op::multiply, selected);
        x6 = original[0];
        x0 = arithmetic(x0, x4, op::multiply, selected);
        x11 = arithmetic(x11, x8, op::subtract, selected);
        x8 = original[2];
        x1 = arithmetic(x1, x0, op::subtract, selected);
        x11 = arithmetic(x11, x12, op::multiply, selected);
        x1 = arithmetic(x1, x12, op::multiply, selected);
        x12 = original[6];
        x3 = arithmetic(x3, x1, op::subtract, selected);
        io.write(destination + 4U, x3);
        x7 = arithmetic(x7, io.read(reference + 8U), op::multiply, selected);
        x7 = arithmetic(x7, x5, op::add, selected);
        x7 = arithmetic(x7, x11, op::subtract, selected);
        x11 = original[5];
        io.write(destination + 8U, x7);
        x7 = original[1];

    return {x0,x1,x2,x3,x4,x5};
}
}
