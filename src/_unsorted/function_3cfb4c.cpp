struct cleared_block {
    unsigned char reserved0[8];
    char field_8;
    unsigned char reserved9[7];
    long long field_10;
    long long field_18;
};

extern "C" cleared_block* function_3cfb4c(cleared_block* block) {
    block->field_8 = 0;
    block->field_10 = 0;
    block->field_18 = 0;
    return block;
}
