struct block16 {
    unsigned char bytes[16];
};

struct block {
    block16 field_0;
    int field_10;
    unsigned char reserved14[0xc];
    block16 field_20;
    int field_30;
    int field_34;
};

extern "C" block* function_688c00(block* dest, block* source) {
    dest->field_0 = source->field_0;
    dest->field_10 = source->field_10;
    dest->field_20 = source->field_20;
    dest->field_30 = source->field_30;
    dest->field_34 = source->field_34;
    return dest;
}
