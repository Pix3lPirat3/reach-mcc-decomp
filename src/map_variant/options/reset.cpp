#include "options.hpp"
namespace hum::reconstruction::reach::parent_options {
result compose_reset(map_variant_reset_dependencies& provider,address variant,std::uint32_t id,
                     address module,address rbp,continuation state) {
    return {reset_map_variant_6c080(provider,variant,id,module,rbp),state};
}
}
