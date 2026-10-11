extern "C" void* hum_memset_78932a(void* destination, int value, unsigned int size);

#pragma pack(push, 1)
struct placement_record {
    unsigned short flags;
    short ref_a;
    int ref_b;
    unsigned char pad0[0x2c - 8];
    short ref_c;
    unsigned char pad1[0x40 - 0x2e];
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
#pragma pack(pop)

static_assert(sizeof(placement_record) == 0x4c, "record stride");

extern "C" placement_record* forge_placement_init_6bb20(placement_record* record) {
    record->b46 = 0;
    hum_memset_78932a(record, 0, 0x4c);
    record->ref_a = -1;
    record->ref_b = -1;
    record->ref_c = -1;
    unsigned char* reserved = &record->b40;
    *reserved = 0;
    record->b4a = -1;
    record->w44 = -1;
    record->b43 = 0;
    record->b47 = 8;
    return record;
}
