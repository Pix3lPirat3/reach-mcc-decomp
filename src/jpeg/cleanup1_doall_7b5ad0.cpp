struct inner_block {
    unsigned char reserved0[0x10];
    int field_10;
    unsigned char reserved14[0xc];
    unsigned int field_20;
};

struct outer_block {
    unsigned char reserved0[8];
    inner_block* field_8;
};

extern "C" inner_block* cleanup1_doall_7b5ad0(outer_block* outer) {
    outer->field_8->field_10 = 0;
    inner_block* inner = outer->field_8;
    inner->field_20 = inner->field_20 | 0xd;
    return inner;
}
