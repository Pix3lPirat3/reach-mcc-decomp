extern "C" int forge_create_variant_object_6ed04(void* state, int index, bool flag);

#pragma pack(push, 1)
struct placement_record {
    unsigned short flags;
    unsigned char pad0[0x2c - 2];
    short ref_c;
    unsigned char pad1[0x4c - 0x2e];
};
struct variant_state {
    unsigned char head[0x14fc];
    placement_record records[651];
};
#pragma pack(pop)

static_assert(sizeof(placement_record) == 0x4c, "record stride");

extern "C" void forge_create_all_6eef4(variant_state* state) {
    for (int i = 0; i < 651; ++i) {
        if (state->records[i].flags & 1) {
            if (-1 == state->records[i].ref_c) {
                forge_create_variant_object_6ed04(state, i, false);
            }
        }
    }
}
