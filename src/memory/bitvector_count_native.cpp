using word32 = unsigned int;
using word16 = unsigned short;
using signed32 = int;
using signed64 = __int64;
using size64 = unsigned __int64;
static_assert(sizeof(word32) == 4);
static_assert(sizeof(word16) == 2);
static_assert(sizeof(signed32) == 4);
static_assert(sizeof(signed64) == 8);
static_assert(sizeof(size64) == 8);
static_assert(sizeof(void*) == 8);
static_assert(static_cast<signed32>(0xffffffffU) == -1);
extern "C" void* __cdecl memcpy(void*, const void*, size64);

__forceinline size64 fold_pairs(size64 value) {
    value = (value & 0x5555555555555555ULL)
        + ((value >> 1) & 0x5555555555555555ULL);
    value = (value & 0x3333333333333333ULL)
        + ((value >> 2) & 0x3333333333333333ULL);
    value = (value & 0x0f0f0f0f0f0f0f0fULL)
        + ((value >> 4) & 0x0f0f0f0f0f0f0f0fULL);
    value = (value & 0x00ff00ff00ff00ffULL)
        + ((value >> 8) & 0x00ff00ff00ff00ffULL);
    return value;
}

extern "C" word32 bitvector_count_native(const void* input, word32 bit_count) {
    word32 total = 0;
    const word32 padded_bits = bit_count + 31U;
    signed32 padded;
    memcpy(&padded, &padded_bits, sizeof(padded));
    const signed64 wide = padded;
    const auto* words = static_cast<const word32*>(input);
    if (((wide >> 5) - 1) > 0) {
        signed64 index = 0;
        do {
            const size64 folded = fold_pairs(words[index]);
            total += static_cast<word32>(folded & 0xffffU);
            total += static_cast<word32>(folded >> 16);
            ++index;
        } while (index < ((wide >> 5) - 1));
    }
    const signed64 final_index = (wide >> 5) - 1;
    const word32 remainder = bit_count & 31U;
    word32 mask = 0xffffffffU;
    if (remainder > 0U) mask >>= 32U - remainder;
    const signed64 tail_word = static_cast<signed32>(words[final_index]);
    const signed64 tail_mask = static_cast<signed32>(mask);
    const size64 folded = fold_pairs(static_cast<size64>(tail_word & tail_mask));
    return total + static_cast<word16>(folded)
        + static_cast<word16>(folded >> 16);
}
