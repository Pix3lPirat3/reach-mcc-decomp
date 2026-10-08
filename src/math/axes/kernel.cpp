#include "kernel.hpp"
#include "kernel_core.hpp"
namespace hum::reconstruction::reach::local1856c {
result project(memory& ram, address module, address entry_rsp,
               volatile_frame r, preserved_frame original) {
    const auto controls = _mm_getcsr() & 0xffc0U;
    if ((controls & 0x1f80U) != 0x1f80U)
        return {outcome::fp_environment_refused, std::nullopt};
    std::array<detail::lane,6> incoming;
    std::array<detail::lane,10> preserved;
    for (unsigned i=0;i<6;++i) incoming[i]=detail::lane::full(r.xmm[i]);
    for (unsigned i=0;i<10;++i) preserved[i]=detail::lane::full(original.xmm[i]);
    try {
        const auto outgoing=detail::execute(ram,module,r.rcx,r.rdx,incoming,preserved,false,controls);
        r.rax=r.rcx; r.r11=entry_rsp;
        for (unsigned i=0;i<6;++i) r.xmm[i]=outgoing[i].complete();
        return {outcome::completed,completed_state{r,original,entry_rsp}};
    } catch (const detail::changed_fp_environment&) {
        return {outcome::fp_environment_refused,std::nullopt};
    }
}
}
