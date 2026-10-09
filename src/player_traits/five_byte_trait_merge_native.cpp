using u8 = unsigned char;
using u32 = unsigned int;
static_assert(sizeof(u8) == 1 && sizeof(u32) == 4);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned long long);
#pragma intrinsic(memcpy)

extern "C" void five_byte_trait_merge_native(void* dst, const void* source, u8 mode) {
    auto* output = static_cast<u8*>(dst);
    const auto* input = static_cast<const u8*>(source);
    u8 a;
    a = input[0];
    if (a < 6) {
        if (a != 0 || mode != 0) output[0] = static_cast<u8>(a);
    } else if (mode != 0) {
        output[0] = 0;
    }
    a = input[1];
    if (a < 4) {
        if (a != 0 || mode != 0) output[1] = static_cast<u8>(a);
    } else if (mode != 0) {
        output[1] = 0;
    }
    a = input[2];
    if (a < 4) {
        if (a != 0 || mode != 0) output[2] = static_cast<u8>(a);
    } else if (mode != 0) {
        output[2] = 0;
    }
    a = input[3];
    if (a < 5) {
        if (a != 0 || mode != 0) output[3] = static_cast<u8>(a);
    } else if (mode != 0) {
        output[3] = 0;
    }
    a = input[4];
    if (a < 14) {
        if (a != 0 || mode != 0) output[4] = static_cast<u8>(a);
    } else if (mode != 0) {
        output[4] = 0;
    }
}
