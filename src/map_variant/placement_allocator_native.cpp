using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;
static_assert(sizeof(u8)==1 && sizeof(u16)==2 && sizeof(u32)==4 && sizeof(u64)==8);

#pragma pack(push, 1)
struct placement_record_76 {
    u16 flags;
    u16 quota_or_folder_index;
    u32 runtime_object_handle;
    float position[3];
    float forward[3];
    float up[3];
    u16 auxiliary_index;
    u8 placement_kind;
    u8 unknown_2f;
    u8 property_bytes_30[16];
    u8 property_byte_40;
    u8 property_byte_41;
    u8 property_byte_42;
    u8 property_byte_43;
    u16 label;
    u8 property_flags;
    u8 team;
    u16 property_word_48;
    u8 color;
    u8 unknown_4b;
};
#pragma pack(pop)
static_assert(sizeof(float)==4 && sizeof(placement_record_76)==76);

extern "C" {

void* hum_memset_78932a(void* destination, int fill, u64 size);

void* memcpy(void* destination, const void* source, u64 size);
}
#pragma intrinsic(memcpy)

template<class T> static void put(u8* destination, T value) {
    memcpy(destination, &value, sizeof(value));
}
template<class T> static T get(const u8* source) {
    T value;
    memcpy(&value, source, sizeof(value));
    return value;
}

extern "C" int hum_map_variant_reserve_6e0c8(void* owner) {
    auto* const bytes = static_cast<u8*>(owner);
    auto* scan = bytes + 0x14fc;
    int selected = 0;

    while ((*scan & 1u) != 0) {
        ++selected;
        scan += 76;
        if (selected == 651) return -1;
    }
    auto* const slot = bytes + 0x14fc + static_cast<u64>(selected) * 76;
    hum_memset_78932a(slot, 0, 76);

    put<u16>(slot + 0x02, 0xffffu);
    put<u32>(slot + 0x04, 0xffffffffu);
    put<u16>(slot + 0x2c, 0xffffu);
    put<u64>(slot + 0x41, 0);
    put<u16>(slot + 0x49, 0);
    put<u8>(slot + 0x4b, 0);
    put<u64>(slot + 0x30, 0);
    put<u64>(slot + 0x38, 0);
    put<u8>(slot + 0x40, 0);
    put<u8>(slot + 0x43, 0);
    put<u8>(slot + 0x4a, 0xffu);
    put<u16>(slot + 0x44, 0xffffu);
    put<u8>(slot + 0x47, 8);
    put<u16>(slot, static_cast<u16>(get<u16>(slot) | 1u));
    put<u8>(slot + 0x46, static_cast<u8>(get<u8>(slot + 0x46) | 0x0cu));
    return selected;
}
