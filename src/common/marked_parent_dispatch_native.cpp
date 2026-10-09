using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;
using byte_count = decltype(sizeof(0));
static_assert(sizeof(u16) == 2 && sizeof(u32) == 4 && sizeof(u64) == 8);
static_assert(sizeof(void*) == 8 && sizeof(byte_count) == 8);
extern "C" void* memcpy(void*, const void*, byte_count);
#if defined(_MSC_VER)
#pragma intrinsic(memcpy)
#endif

extern "C" void supplied_update_then_mark(u32 token_bits, bool predicate,
    bool third_argument, u32 fourth_bits, u32 fifth_bits);

static inline u16 read16_at(u64 location) {
    u16 value;
    memcpy(&value, reinterpret_cast<const void*>(location), 2);
    return value;
}

extern "C" u8 target_75e050(u64, u32 token_bits, u64 input_bits) {

    const u16 compared_bits = read16_at(input_bits + u64{2});
    supplied_update_then_mark(token_bits, compared_bits == u16{1}, true,
                             u32{1}, u32{0});
    return u8{1};
}
