#include "presence_core.hpp"
namespace recon1703 {
Registers read_flag(Memory& memory,Registers incoming) {
    return flag_shared_detail::read_flag_core(memory,incoming);
}
}
