#include "apply_wrapped_quota_delta_and_notify.hpp"

namespace recon457 {
namespace {
struct getter_reads {
    memory& data;
    std::uint32_t index=0;
    address block=0;
    unsigned qwords=0;
};
address gs(void* p) {return static_cast<getter_reads*>(p)->data.read_gs64(0x58u);}
std::uint32_t dword(void* p,address a) {
    auto& reads=*static_cast<getter_reads*>(p);
    reads.index=reads.data.read32(a);return reads.index;
}
address qword(void* p,address a) {
    auto& reads=*static_cast<getter_reads*>(p);
    const auto value=reads.data.read64(a);
    if(reads.qwords++==0u)reads.block=value;
    return value;
}
std::uint8_t byte(void* p,address a) {return static_cast<getter_reads*>(p)->data.read8(a);}
address replace_low(address x,std::uint8_t b) {return (x&~address{255})|b;}
bool signed_ge(std::uint32_t a,std::uint32_t b) {return (a^0x80000000u)>=(b^0x80000000u);}
}
registers getter_6bcec(memory& m,address module,registers r) {
    getter_reads observed{m};
    const hum::reconstruction::reach::map_context_getter_private::dependencies reader{
        &observed,module,gs,qword,dword,byte};
    r.rax=hum::reconstruction::reach::map_context_getter_private::map_context_getter(reader);
    r.rdx=r.rax;r.rcx=observed.index;r.r8=observed.block;
    return r;
}
registers apply_wrapped_quota_delta_and_notify(memory& m,address module,address working,registers r) {
    auto saved_b=static_cast<std::uint8_t>(r.rdx);
    const auto index=static_cast<std::uint32_t>(r.rcx);
    r.r9=(index&0x80000000u)!=0u?address{index}|0xffffffff00000000ull:index;
    r=m.call_71540(r);
    if((r.rax&255u)==0u)return r;
    r=getter_6bcec(m,module,r);
    r.rdx=static_cast<std::uint32_t>(r.r9);
    const auto offset=r.r9+r.r9*2u;
    const auto object=r.rax;
    const auto record=recon453::body_6cf60(m,m,module,
        {working-8u,r.rcx,r.rdx,r.r10,r.r11});
    r={record.rax,record.rcx,record.rdx,record.r8,record.r9,record.r10,record.r11};
    auto d=m.read8(object+offset+0xd641u);
    r.rdx=replace_low(r.rdx,d);r.r9=r.rax;
    r.rax=m.read_gs64(0x58u);
    d=static_cast<std::uint8_t>(d+saved_b);
    r.rdx=replace_low(r.rdx,d);
    saved_b=static_cast<std::uint8_t>(saved_b+m.read8(object+offset+0xd642u));
    r.rcx=m.read32(module+0xc17b18u);r.r8=0x48u;
    m.write8(object+offset+0xd641u,d);m.write8(object+offset+0xd642u,saved_b);
    r.rax=m.read64(r.rax+r.rcx*8u);r.r8=m.read64(r.rax+r.r8);
    if(m.read8(r.r8+0x11u)!=4u&&saved_b==0u) {
        m.write8(object+offset+0xd641u,0);d=0;r.rdx=replace_low(r.rdx,0);
    }
    r.rcx=d;r.rax=saved_b;
    if(d<=saved_b)r.rcx=r.rax;
    r.rax=m.read8(r.r9+0x10u);r.rdx=static_cast<std::uint8_t>(r.rcx);
    const auto limit=m.read32(r.r9+0x10u);
    r.rcx=r.rdx;
    if(signed_ge(static_cast<std::uint32_t>(r.rdx),limit))r.rcx=r.rax;
    r.rax=saved_b;
    m.write8(object+offset+0xd641u,static_cast<std::uint8_t>(r.rcx));
    r.rcx=m.read8(object+offset+0xd640u);
    if(r.rcx==0u)r.rcx=0;
    if(r.rcx<r.rax)r.rax=r.rcx;
    m.write8(object+offset+0xd640u,static_cast<std::uint8_t>(r.rax));
    if(m.read8(r.r8+0x11u)==4u)return r;
    r=getter_6bcec(m,module,r);r.rcx=r.rax;
    r=m.call_6dd80(r);r.rcx=0x100000u;
    return m.call_3a5be8(r);
}
}
