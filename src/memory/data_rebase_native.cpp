using uint64 = unsigned long long;
static_assert(sizeof(uint64) == 8 && sizeof(void*) == 8);

extern "C" __declspec(noinline) void data_set_new_base_address(
    void* destination_slot, void* new_base) noexcept {
    const uint64 base_bits = reinterpret_cast<uint64>(new_base);
    if (new_base) {
        auto* words = static_cast<uint64*>(new_base);
        uint64 offset = words[12];
        if (offset) {
            const uint64 pointer = base_bits + offset;
            if (words[10] != pointer) words[10] = pointer;
        } else {
            words[10] &= 0;
        }
        offset = words[13];
        if (offset) {
            offset += base_bits;
            if (words[11] != offset) words[11] = offset;
        } else {
            words[11] &= 0;
        }
    }
    *static_cast<uint64*>(destination_slot) = base_bits;
}
