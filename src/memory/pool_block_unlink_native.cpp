using byte = unsigned char;
using u32 = unsigned int;
using u64 = unsigned long long;
using byte_count = decltype(sizeof(0));
static_assert(sizeof(byte) == 1 && sizeof(u32) == 4 && sizeof(u64) == 8,
              "Windows x64 fixed widths");
extern "C" void* memcpy(void*, const void*, byte_count);
#if defined(_MSC_VER)
#pragma intrinsic(memcpy)
#endif

static inline u32 load32(const byte* p) {
    u32 value;
    memcpy(&value, p, 4);
    return value;
}
static inline u64 load64(const byte* p) {
    u64 value;
    memcpy(&value, p, 8);
    return value;
}
static inline void store32(byte* p, u32 value) { memcpy(p, &value, 4); }
static inline void store64(byte* p, u64 value) { memcpy(p, &value, 8); }

extern "C" void target_68a424(byte* pool, u32 payload_offset) {
    const u32 header_offset = payload_offset - 0x10u;
    byte* const block_bytes = pool + static_cast<u64>(header_offset);
    const u32 hint = load32(pool + 0x54);
    if (hint == header_offset) {
        const u32 link0c_for_hint = load32(block_bytes + 0x0c);
        store32(pool + 0x54, link0c_for_hint);
    }
    const u32 amount = load32(block_bytes);
    const u64 accounting = load64(pool + 0x40);
    store64(pool + 0x40, accounting + static_cast<u64>(amount));

    const u32 link0c_for_test = load32(block_bytes + 0x0c);
    const u32 cached_link08 = load32(block_bytes + 8);
    if (link0c_for_test != 0) {
        const u32 link0c_for_address = load32(block_bytes + 0x0c);
        store32(pool + static_cast<u64>(link0c_for_address) + 8,
                cached_link08);
    } else {
        store32(pool + 0x4c, cached_link08);
    }

    const u32 link08_for_test = load32(block_bytes + 8);
    const u32 cached_link0c = load32(block_bytes + 0x0c);
    if (link08_for_test != 0) {
        const u32 link08_for_address = load32(block_bytes + 8);
        store32(pool + static_cast<u64>(link08_for_address) + 0x0c,
                cached_link0c);
        return;
    }
    store32(pool + 0x50, cached_link0c);
}
