struct source_record {
    unsigned char reserved0[0x24];
    int field_24;
};

struct target_record {
    unsigned char reserved0[6];
    unsigned short field_6;
    int field_8;
};

extern "C" long long object_get_payload_by_type_mask_4739cc(int handle, unsigned int mask);

extern "C" char function_75d318(long long, long long, source_record* source, target_record* target) {
    int handle = source->field_24;
    char found = 0;
    if (handle != -1 && object_get_payload_by_type_mask_4739cc(handle, 0xFFFFFFFF) != 0) {
        target->field_8 = handle;
        found = 1;
    }
    target->field_6 = target->field_6 | 0x20;
    return found;
}
