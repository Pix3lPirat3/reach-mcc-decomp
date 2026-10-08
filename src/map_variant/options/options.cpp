#include "options.hpp"
#ifndef OPTIONS_INITIALIZE
#define OPTIONS_INITIALIZE initialize
#endif
#ifndef OPTIONS_SANITIZE
#define OPTIONS_SANITIZE sanitize
#endif
#ifndef OPTIONS_MUTANT
#define OPTIONS_MUTANT 0
#endif
namespace hum::reconstruction::reach::parent_options {
namespace {
[[maybe_unused]] address embedded(address parent) {
#if OPTIONS_MUTANT == 1
    return (parent+0x110e3)&~address{7};
#else
    return (parent+0x110e3)&~address{3};
#endif
}
}
result OPTIONS_INITIALIZE(memory& m,dependencies& d,address module,address parent,continuation state) {
#if OPTIONS_MUTANT == 2
    constexpr std::uint32_t extent=0x1ea9c;
#else
    constexpr std::uint32_t extent=0x1eaa0;
#endif
    state=d.fill_78932a(m,parent,0,extent,state);
    const auto byte=static_cast<std::uint8_t>(m.read(module+0x4e2fca1,1));

    const bool nonnull=m.read(module+0xc1a230,8)!=0;
    m.write(parent+0x1c9,1,byte);
    m.write(parent+6,2,0x3c);
    m.write(parent,2,0x101);
    std::uint32_t selected=0;
    if(nonnull) {
        const auto pointer=m.read(module+0xc1a238,8);
        const auto compared=static_cast<std::uint32_t>(m.read(pointer,4));

        const auto reloaded=static_cast<std::uint32_t>(m.read(pointer,4));
        if(compared<=11U) selected=reloaded;
    }
    const auto xmm1=m.read128(module+0x985c10);
    m.write(parent+0x14,4,selected);
    const address optional=parent+0x18;
    m.write(parent+3,1,0xff);
    const auto xmm0=m.read128(module+0x985c10);
    const auto old3c=static_cast<std::uint32_t>(m.read(parent+0x3c,4));
    m.write(parent+0x3c,4,old3c|0xffffffffU);
    const auto old40=static_cast<std::uint32_t>(m.read(parent+0x40,4));
    m.write(parent+0x40,4,old40|0xffffffffU);
    m.write(parent+0x1d4,1,1);
    m.write(parent+0x110dc,2,0xff00);
    m.write128(parent+0x1c,xmm0);
    m.write128(parent+0x2c,xmm1);
    if(optional!=0) m.write(optional,4,4);
    state=d.call_3a92d8(m,8,parent+8,state);
    const address payload=parent+0x14d8;
    m.write(parent+0x10,4,0x78a8);
    state=d.call_37334(m,payload,3,state);
#if OPTIONS_MUTANT == 3
    return {std::nullopt,state};
#else
    return d.reset_6c080(m,embedded(parent),0xffffffffU,state);
#endif
}
result OPTIONS_SANITIZE(memory& m,dependencies& d,address parent,continuation state) {
    state=d.call_42d4c(m,parent+0x14d8,state);
#if OPTIONS_MUTANT == 3
    return {std::nullopt,state};
#else
    return d.validate_6c948(m,embedded(parent),0xffffffffU,state);
#endif
}
}
