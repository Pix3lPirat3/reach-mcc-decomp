using word = unsigned short;
using count64 = unsigned __int64;
using address64 = unsigned __int64;
static_assert(sizeof(word) == 2);
static_assert(sizeof(count64) == 8);
static_assert(sizeof(void*) == 8);

extern "C" void* target_35c3c(void* destination, const void* source,
    count64 count) {
    auto* output = static_cast<word*>(destination);
    auto* input = static_cast<const word*>(source);
    const count64 last = count - 1;
    count64 copied = 0;
    do {
        const word value = *input;
        output[copied] = value;
        if (value == 0) break;
        ++input;
        ++copied;
    } while (copied <= last);
    const auto terminal = reinterpret_cast<address64>(destination)
        + count * 2 - 2;
    *reinterpret_cast<word*>(terminal) = 0;
    return destination;
}
