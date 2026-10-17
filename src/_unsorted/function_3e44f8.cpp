struct state_block {
    unsigned char reserved0[0x1F8DC];
    int current;
    unsigned char reserved1F8E0[0xA01C];
    int count;
};

extern "C" char function_3e44f8(state_block* block) {
    return block->current == block->count - 1;
}
