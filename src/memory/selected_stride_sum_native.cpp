using u32 = unsigned int;
using u64 = unsigned long long;

static_assert(sizeof(u32) == 4 && sizeof(int) == 4 && sizeof(u64) == 8);
static_assert(sizeof(void*) == 8 && sizeof(long long) == 8);

extern "C" {
extern unsigned char stride_root_bits_c1a230[8];
extern unsigned char stride_base_bits_4e39f20[128];
void* memcpy(void*, const void*, u64);
}

extern "C" u32 selected_stride_sum_native(const void*, int count, u32 addend) {
    u32 sum = 0;
    long long remaining = count;
    if (count > 0) {
        u64 root;
        memcpy(&root, stride_root_bits_c1a230, 8);
        u32 tag;
        memcpy(&tag, reinterpret_cast<const void*>(root + 0x22c), 4);
        u64 base;
        memcpy(&base, stride_base_bits_4e39f20 + (static_cast<u64>(tag) >> 28) * 8, 8);
        u64 address = base + 4 * (static_cast<u64>(tag) + 2);
        do {
            u32 value;
            memcpy(&value, reinterpret_cast<const void*>(address), 4);
            sum += value;
            address += 20;
            --remaining;
        } while (remaining != 0);
    }
    return sum + addend;
}
