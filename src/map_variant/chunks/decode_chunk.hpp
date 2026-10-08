#pragma once
#include <cstddef>
#include <cstdint>

namespace hum::reconstruction::reach {

struct map_chunk_decode_dependencies {
    std::uint8_t (*initialize_hash_2037c)(void* storage, std::int32_t size) noexcept;
    std::int32_t (*hash_data)(void* handle, const void* data,
                              std::uint32_t size, std::uint32_t flags) noexcept;
    void (*finish_hash_20420)(void* storage, void* digest20) noexcept;
    void (*reset_reader_dcd48)(void* reader, std::uint32_t mode) noexcept;
    std::uint8_t (*decode_6d468)(void* destination, void* reader) noexcept;
    const volatile std::uint8_t* require_matching_digest_4e2fb49;
};

std::uint8_t decode_map_chunk(const void* chunk, void* destination,
                             const map_chunk_decode_dependencies& deps) noexcept;
}
