using u8 = unsigned char;
using u32 = unsigned int;
static_assert(sizeof(u8) == 1 && sizeof(u32) == 4);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned long long);
#pragma intrinsic(memcpy)

extern "C" void movement_trait_merge_native(void* dst, const void* source, u8 mode) {
    auto* output = static_cast<u8*>(dst);
    const auto* input = static_cast<const u8*>(source);
    u32 h;
    u32 a;
    memcpy(&h, input, 4);
    a = h & 0xffu;
    if (a <= 17) {
        if (a != 0 || mode != 0) output[0] = static_cast<u8>(a);
    } else if (mode != 0) {
        output[0] = 0;
    }
    memcpy(&h, input + 1, 4);
    a = h & 0xffu;
    if (a <= 13) {
        if (a != 0 || mode != 0) output[1] = static_cast<u8>(a);
    } else if (mode != 0) {
        output[1] = 0;
    }
    memcpy(&h, input + 2, 4);
    a = h & 0xffu;
    if (a < 9) {
        if (a != 0 || mode != 0) output[2] = static_cast<u8>(a);
    } else if (mode != 0) {
        output[2] = 0;
    }
    memcpy(&h, input + 3, 4);
    a = h & 0xffu;
    if (a < 4) {
        if (a != 0 || mode != 0) output[3] = static_cast<u8>(a);
    } else if (mode != 0) {
        output[3] = 0;
    }
    u32 d;
    memcpy(&d, input + 4, 4);
    if (d + 1 <= 401u) {
        if (d != 0xffffffffu || mode != 0) memcpy(output + 4, &d, 4);
    } else if (mode != 0) {
        d = 0xffffffffu;
        memcpy(output + 4, &d, 4);
    }
}
