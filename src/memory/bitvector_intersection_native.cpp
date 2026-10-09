using word32 = unsigned int;
using signed32 = int;
static_assert(sizeof(word32) == 4);
static_assert(sizeof(signed32) == 4);
static_assert(sizeof(void*) == 8);

extern "C" bool bitvector_intersection_native(word32 bit_count, const word32* left, const word32* right, word32* output) noexcept {
    bool any = false;
    for (signed32 index = (static_cast<signed32>(bit_count + 31U) >> 5) - 1; index >= 0; --index) {
        const word32 intersection = left[index] & right[index];
        if (output != nullptr) output[index] = intersection;
        if (intersection != 0) any = true;
    }
    return any;
}
