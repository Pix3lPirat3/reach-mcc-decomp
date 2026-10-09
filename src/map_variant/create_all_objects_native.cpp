using u8 = unsigned char;
using i16 = short;
using u64 = unsigned long long;
static_assert(sizeof(i16) == 2 && sizeof(int) == 4 && sizeof(void*) == 8);
extern "C" void* memcpy(void*, const void*, u64);
extern "C" int create_variant_object_native(const void*, int, bool);
extern "C" void create_all_objects_native(const void* variant) {
    u64 cursor = reinterpret_cast<u64>(variant) + 0x1528;
    int index = 0;
    do {
        u8 flags;
        memcpy(&flags, reinterpret_cast<const void*>(cursor - 0x2c), 1);
        if ((flags & 1) != 0) {
            i16 reference;
            memcpy(&reference, reinterpret_cast<const void*>(cursor), 2);
            int none = -1;
            i16 sentinel;
            memcpy(&sentinel, &none, 2);
            if (reference == sentinel) {
                create_variant_object_native(variant, index, false);
            }
        }
        ++index;
        cursor += 0x4c;
    } while (index < 651);
}