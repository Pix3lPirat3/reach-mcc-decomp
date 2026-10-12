struct source_block {
    unsigned char reserved0[0x10];
    int field_10;
    unsigned char reserved14[0x5C];
    int field_70;
    unsigned char reserved74[0x5C];
    int field_d0;
    unsigned char reserved_d4[0x5C];
    int field_130;
};

struct owner {
    unsigned char reserved0[0x20];
    source_block* block;
};

extern "C" int function_9122f0(owner* self, int* out) {
    source_block* block = self->block;
    out[0] = block->field_10;
    out[1] = block->field_70;
    out[2] = block->field_d0;
    int last = block->field_130;
    out[3] = last;
    return last;
}
