#include "decode_chunk.hpp"
#include <cstring>

namespace hum::reconstruction::reach {
namespace {
template<class T> T load(const std::byte* address) noexcept {
    T value;
    std::memcpy(&value, address, sizeof(value));
    return value;
}
template<class T> void store(std::byte* address, T value) noexcept {
    std::memcpy(address, &value, sizeof(value));
}
}

std::uint8_t decode_map_chunk(const void* chunk, void* destination,
                             const map_chunk_decode_dependencies& deps) noexcept {
    const auto* bytes = static_cast<const std::byte*>(chunk);
    const std::uint32_t wire = load<std::uint32_t>(bytes + 0x20);
    const std::uint32_t length = ((wire & 0xffu) << 24) |
        ((wire & 0xff00u) << 8) | ((wire >> 8) & 0xff00u) | (wire >> 24);

    alignas(8) std::byte hash_storage[0x58];
    if (deps.initialize_hash_2037c(hash_storage, 0x58) == 0)
        return 0;

    if (length > 0x7000u)
        return 0;
    deps.hash_data(load<void*>(hash_storage), &length, 4, 0);
    deps.hash_data(load<void*>(hash_storage), bytes + 0x24, length, 0);
    alignas(8) std::byte digest[20];

    deps.finish_hash_20420(hash_storage, digest);
    bool equal = load<std::uint64_t>(bytes + 0x0c) == load<std::uint64_t>(digest);
    if (equal)
        equal = load<std::uint64_t>(bytes + 0x14) == load<std::uint64_t>(digest + 8);
    if (equal)
        equal = load<std::uint32_t>(bytes + 0x1c) == load<std::uint32_t>(digest + 16);

    if (*deps.require_matching_digest_4e2fb49 != 0 && !equal)
        return 0;

    alignas(8) std::byte reader[0xd0];
    store(reader, bytes + 0x24);
    store(reader + 8, bytes + 0x7024);
    store(reader + 0x10, std::uint32_t{0x7000});
    store(reader + 0x14, std::uint32_t{1});
    deps.reset_reader_dcd48(reader, 0);
    deps.reset_reader_dcd48(reader, 3);
    return deps.decode_6d468(destination, reader);
}
}
