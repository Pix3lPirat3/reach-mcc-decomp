#include "kernel_effects.hpp"
#include "kernel_core.hpp"
#include <limits>
namespace hum::reconstruction::reach::local1856c {
namespace {
bool span(address at,std::uint64_t width) {
    return at<=std::numeric_limits<address>::max()-width;
}
bool overlap(address a,std::uint64_t aw,address b,std::uint64_t bw) {
    return a<b+bw && b<a+aw;
}
}
effects_outcome project_effects(effects_memory& ram,address module,effects_request r) {
    const auto controls=_mm_getcsr()&0xffc0U;
    if (controls!=0x1f80U) return effects_outcome::fp_environment_refused;
    if (!span(module,0xa8af1cU)||!span(r.destination,12)||!span(r.reference,12))
        return effects_outcome::ownership_refused;
    const auto global=module+0xa8af18U;
    if (overlap(r.destination,12,r.reference,12)||overlap(r.destination,12,global,4)||
        overlap(r.reference,12,global,4)||!ram.owns(r.destination,12)||
        !ram.owns(r.reference,12)||!ram.owns(global,4))
        return effects_outcome::ownership_refused;
    std::array<detail::lane,6> incoming{};
    std::array<detail::lane,10> unavailable_preserved{};
    if (r.coefficient2_low) incoming[2]=detail::lane::low(*r.coefficient2_low);
    if (r.coefficient3_low) incoming[3]=detail::lane::low(*r.coefficient3_low);
    try {
        (void)detail::execute(ram,module,r.destination,r.reference,incoming,
                              unavailable_preserved,true,controls);
        return effects_outcome::completed;
    } catch (const detail::changed_fp_environment&) {
        return effects_outcome::fp_environment_refused;
    } catch (const detail::unavailable_input&) {
        return effects_outcome::unavailable_consumed_input;
    } catch (const detail::selected_domain_refused&) {
        return effects_outcome::domain_refused;
    }
}
}
