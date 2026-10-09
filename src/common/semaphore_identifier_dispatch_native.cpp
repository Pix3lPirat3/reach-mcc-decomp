using u8 = unsigned char;
using u32 = unsigned int;
using u64 = unsigned long long;
using byte_count = decltype(sizeof(0));
static_assert(sizeof(u32) == 4 && sizeof(u64) == 8);
static_assert(sizeof(void*) == 8 && sizeof(byte_count) == 8);
extern "C" void* memcpy(void*, const void*, byte_count);
#if defined(_MSC_VER)
#pragma intrinsic(memcpy)
#endif

extern "C" void supplied_release_identifier(u32 identifier_bits);

static inline u32 read32_at(u64 location) {
    u32 value;

    memcpy(&value, reinterpret_cast<const void*>(location), 4);
    return value;
}

extern "C" void target_68af10(u64 core_bits) {
    u32 counter = 0;

    while (counter < read32_at(core_bits + u64{0x8c054})) {
        const u32 identifier_bits = read32_at(core_bits + u64{0x74018});
        supplied_release_identifier(identifier_bits);
        ++counter;

    }
}
