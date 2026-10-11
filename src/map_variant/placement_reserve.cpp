extern "C" void* hum_memset_78932a(void* destination, int value, unsigned int size);
extern "C" void* memset(void* destination, int value, unsigned long long size);
#pragma intrinsic(memset)

#pragma pack(push, 1)
struct placement_record {
    unsigned short flags;
    short ref_a;
    int ref_b;
    unsigned char pad0[0x2c - 8];
    short ref_c;
    unsigned char pad1[2];
    long long q30;
    long long q38;
    unsigned char b40;
    unsigned char pad2[2];
    unsigned char b43;
    short w44;
    unsigned char b46;
    unsigned char b47;
    unsigned char pad3[2];
    signed char b4a;
    unsigned char pad4;
};
struct placement_tail {
    long long q;
    short w;
    unsigned char b;
    unsigned char pad[0x4c - 11];
};
struct variant_state {
    unsigned char head[0x14fc];
    placement_record records[651];
};
struct variant_state_tail_view {
    unsigned char head[0x153d];
    placement_tail tails[651];
};
#pragma pack(pop)

static_assert(sizeof(placement_record) == 0x4c, "record stride");
static_assert(sizeof(placement_tail) == 0x4c, "tail stride");

extern "C" int forge_reserve_first_free_6e0c8(variant_state* state) {
    int result = -1;
    for (int i = 0; i < 651; ++i) {
        if (!(state->records[i].flags & 1)) {
            result = i;
            break;
        }
    }
    if (result != -1) {
        int index = result;
        placement_record* r = &state->records[index];
        hum_memset_78932a(r, 0, 0x4c);
        r->ref_a = -1;
        r->ref_b = -1;
        r->ref_c = -1;
        placement_tail* t = &reinterpret_cast<variant_state_tail_view*>(state)->tails[index];
        t->q = 0;
        t->w = 0;
        t->b = 0;
        memset(&r->q30, 0, 16);
        r->b40 = 0;
        r->b43 = 0;
        r->b4a = -1;
        r->w44 = -1;
        r->b47 = 8;
        unsigned short* flags = &r->flags;
        unsigned char* b46 = &r->b46;
        *flags |= 1;
        *b46 |= 0xc;
    }
    return result;
}
