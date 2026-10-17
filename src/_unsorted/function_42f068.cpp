struct flags_block {
    unsigned char field_0;
    unsigned char reserved1[3];
    unsigned char field_4;
    unsigned char reserved5[0x10B];
    unsigned char field_110;
};

extern "C" flags_block* function_42f068(flags_block* item) {
    item->field_0 = 0;
    item->field_4 = 0;
    item->field_110 = 0;
    return item;
}
