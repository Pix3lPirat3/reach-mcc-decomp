#include "hash.hpp"

namespace hum::reconstruction::reach::crypto_hash_wrappers {
static bool succeeded(std::uint64_t raw) { return (raw & 0x80000000ULL) == 0; }
static std::uint64_t with_al(std::uint64_t raw, bool value) {
    return (raw & ~0xffULL) | static_cast<std::uint64_t>(value);
}
static std::uint64_t signed_size(std::uint32_t bits) {
    return (bits & 0x80000000u) != 0 ? 0xffffffff00000000ULL | bits : bits;
}

std::uint64_t initialize_2037c(dependencies& memory, address module_base,
    address storage, std::uint32_t size_bits, initializer_frame frame) {
    const auto provider_storage = module_base + 0x24fb810;

    memory.write64(frame.working_rsp + 0x68, frame.incoming_r9);
    bool ready = true;
    if (memory.read64(provider_storage) == 0) {
        ready = succeeded(memory.open_algorithm_provider(provider_storage,
            module_base + 0x98fb08, 0, 0));
    }
    auto raw = memory.fill_at_78932a(storage, 0, signed_size(size_bits));
    if (ready) {

        (void)memory.read32(frame.working_rsp + 0x30);
        memory.write32(frame.working_rsp + 0x30, 0);
        (void)memory.read32(frame.working_rsp + 0x28);
        memory.write32(frame.working_rsp + 0x28, 0);
        const auto provider = memory.read64(provider_storage);
        (void)memory.read64(frame.working_rsp + 0x20);
        memory.write64(frame.working_rsp + 0x20, 0);
        (void)memory.read64(frame.working_rsp + 0x68);
        memory.write64(frame.working_rsp + 0x68, 0);
        raw = memory.create_hash(provider, frame.working_rsp + 0x68, 0, 0, 0, 0, 0);
        const auto handle = memory.read64(frame.working_rsp + 0x68);
        memory.write64(storage, handle);
        ready = succeeded(raw);
    }
    return with_al(raw, ready);
}

std::uint64_t finalize_20420(dependencies& memory, address handle_storage,
    address output) {
    const auto handle = memory.read64(handle_storage);
    (void)memory.finish_hash(handle, output, 20, 0);
    return memory.destroy_hash(handle);
}

std::uint64_t hash_20304(dependencies& memory, address module_base,
    address input, std::uint64_t length_bits, address output,
    hash_workspace workspace) {
    auto raw = initialize_2037c(memory, module_base, workspace.handle_storage, 8,
        {workspace.initializer_working_rsp, output});
    if ((raw & 0xff) == 0) return with_al(raw, false);
    const auto handle = memory.read64(workspace.handle_storage);
    (void)memory.hash_data(handle, input, static_cast<std::uint32_t>(length_bits), 0);
    raw = finalize_20420(memory, workspace.handle_storage, output);
    return with_al(raw, true);
}
}
