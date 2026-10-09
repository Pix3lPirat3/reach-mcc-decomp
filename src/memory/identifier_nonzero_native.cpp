using uint16 = unsigned short;
using uint32 = unsigned int;
using uint64 = unsigned long long;
static_assert(sizeof(uint16) == 2 && sizeof(uint32) == 4 && sizeof(uint64) == 8);
static_assert(sizeof(void*) == 8);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned long long);
#pragma intrinsic(memcpy)

extern "C" __declspec(noinline) bool identifier_nonzero_d114(const void* identifier) noexcept {
    const auto* bytes = static_cast<const unsigned char*>(identifier);
    bool result = false;
    uint32 first;
    uint16 second;
    uint16 third;
    unsigned char byte9;
    uint64 suffix;
    memcpy(&first, bytes, sizeof(first));
    if (first != 0) goto nonzero;
    memcpy(&second, bytes + 4, sizeof(second));
    if (second != 0) goto nonzero;
    memcpy(&third, bytes + 6, sizeof(third));
    if (third != 0) goto nonzero;
    byte9 = bytes[9];
    suffix = bytes[8];
    suffix = (suffix << 8) | byte9;
    suffix = (suffix << 8) | bytes[10];
    suffix = (suffix << 8) | bytes[11];
    suffix = (suffix << 8) | bytes[12];
    suffix = (suffix << 8) | bytes[13];
    suffix = (suffix << 8) | bytes[14];
    suffix = (suffix << 8) | bytes[15];
    if (suffix == 0) goto done;
nonzero:
    result = true;
done:
    return result;
}
