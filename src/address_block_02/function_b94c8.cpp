struct entry_state {
    long long field_0;
    unsigned char reserved8[0x14];
    unsigned short field_1c;
    unsigned char reserved1e[0x62];
    int field_80;
    int field_84;
    unsigned char field_88;
    unsigned char reserved89[0x77];
};

extern "C" long long function_78932a(long long dest, long long value, long long size);

extern "C" entry_state* function_b94c8(entry_state* entry) {
    entry->field_1c = 0;
    function_78932a((long long)entry + 0x58, 0, 0x20);
    entry->field_80 = -1;
    entry->field_84 = 0;
    entry->field_88 = 2;
    return entry;
}
