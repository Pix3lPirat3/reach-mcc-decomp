#pragma once
#include <cstdint>

namespace hum::reconstruction::reach::crypto_hash_wrappers {
using address = std::uint64_t;

struct dependencies {
    virtual ~dependencies() = default;
    virtual std::uint32_t read32(address location) = 0;
    virtual std::uint64_t read64(address location) = 0;
    virtual void write32(address location, std::uint32_t bits) = 0;
    virtual void write64(address location, std::uint64_t bits) = 0;
    virtual std::uint64_t open_algorithm_provider(address provider_storage,
        address algorithm_name, address implementation, std::uint32_t flags) = 0;
    virtual std::uint64_t fill_at_78932a(address destination,
        std::uint32_t value, std::uint64_t count) = 0;
    virtual std::uint64_t create_hash(address provider, address handle_storage,
        address object_buffer, std::uint32_t object_length, address secret,
        std::uint32_t secret_length, std::uint32_t flags) = 0;
    virtual std::uint64_t hash_data(address handle, address input,
        std::uint32_t length, std::uint32_t flags) = 0;
    virtual std::uint64_t finish_hash(address handle, address output,
        std::uint32_t length, std::uint32_t flags) = 0;
    virtual std::uint64_t destroy_hash(address handle) = 0;
};

struct initializer_frame { address working_rsp; std::uint64_t incoming_r9; };
struct hash_workspace { address handle_storage; address initializer_working_rsp; };

std::uint64_t initialize_2037c(dependencies& memory, address module_base,
    address storage, std::uint32_t size_bits, initializer_frame frame);

std::uint64_t finalize_20420(dependencies& memory, address handle_storage,
    address output);

std::uint64_t hash_20304(dependencies& memory, address module_base,
    address input, std::uint64_t length_bits, address output,
    hash_workspace workspace);

}
