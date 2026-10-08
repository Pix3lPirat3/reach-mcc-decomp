#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <span>

namespace hum::historical_payload {

enum class Status {
    complete, need_dictionary, data_error, buffer_error, memory_error,
    stream_error, version_error, unexpected_library_status, out_of_domain
};
enum class AllocatorPolicy { stable, mutate_protected_context_control };
struct Profile {
    std::uint32_t max_m = 4096;
    std::uint32_t max_h = 4096;
    std::uint64_t allocation_budget = 512 * 1024;
    AllocatorPolicy allocator_policy = AllocatorPolicy::stable;
};
struct AllocationEvent {
    std::uint32_t id = 0;
    std::uint32_t items = 0;
    std::uint32_t item_size = 0;
    std::uint64_t bytes = 0;
    bool allocated = false;
    bool freed = false;
    bool forced_cleanup = false;
};
struct Ledger {
    std::array<AllocationEvent, 64> events{};
    std::size_t event_count = 0;
    std::uint64_t live_bytes = 0;
    std::uint64_t peak_bytes = 0;
    std::uint32_t allocation_count = 0;
    std::uint32_t free_count = 0;
    std::uint32_t budget_failures = 0;
    std::uint32_t forced_cleanup_count = 0;
    bool callback_domain_violation = false;
};
struct Result {
    Status status = Status::out_of_domain;
    bool library_init_called = false;
    bool library_step_called = false;
    bool library_end_called = false;
    int library_init_status = 0;
    int library_step_status = 0;
    int library_end_status = 0;
    std::uint32_t m = 0;
    std::uint32_t h = 0;
    std::uint32_t published_l = 0;
    std::uint32_t local_length = 0;
    std::uint32_t offered_input = 0;
    std::uint32_t remaining_input = 0;
    std::uint32_t remaining_output = 0;
    std::uint64_t library_total_in = 0;
    std::uint64_t library_total_out = 0;
    Ledger allocator{};
};

Result decode(std::span<const std::uint8_t> frame, std::uint32_t m,
              std::uint32_t published_l, std::span<std::uint8_t> output,
              const Profile& profile = {});
const char* status_name(Status status) noexcept;
}
