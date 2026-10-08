#include "decode_core.hpp"
namespace hum::reconstruction::reach::recon1550 {
state decode(dependencies& d,address module,address frame,state incoming) {
    return position_shared_detail::decode_core(d,module,frame,incoming);
}
}
