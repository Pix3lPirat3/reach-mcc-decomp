#include "getter.hpp"

namespace hum::reconstruction::reach::map_context_getter_private {

std::uint64_t map_context_getter(const dependencies& reads)
{

    const std::uint64_t tls_array = reads.read_gs_58(reads.user);
    const std::uint32_t tls_index = reads.read_u32(
        reads.user, reads.module_base + UINT64_C(0xc17b18));
    const std::uint64_t tls_block = reads.read_u64(
        reads.user, tls_array + std::uint64_t{tls_index} * UINT64_C(8));
    const std::uint64_t context = reads.read_u64(
        reads.user, tls_block + UINT64_C(0x48));

    if (reads.read_u8(reads.user, context + UINT64_C(0x10)) != 3) {
        return 0;
    }

    const std::uint64_t storage = reads.read_u64(
        reads.user, tls_block + UINT64_C(0x290));
    if (storage == 0) {
        return 0;
    }

    return (storage + UINT64_C(0x30b)) & ~UINT64_C(3);
}

}
