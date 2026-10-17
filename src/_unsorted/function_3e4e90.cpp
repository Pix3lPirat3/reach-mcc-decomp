struct state_block {
    unsigned char reserved0[0x1B45C];
    int current;
    unsigned char reserved1B460[0xE01C];
    int count;
};

extern "C" char function_3e4e90(state_block* block) {
    return block->current == block->count - 1;
}
