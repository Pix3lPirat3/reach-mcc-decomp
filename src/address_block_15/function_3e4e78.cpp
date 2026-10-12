struct state_block {
    unsigned char reserved0[0x1B418];
    int values[0x1C16];
    int count;
};

extern "C" char function_3e4e78(state_block* block, int index) {
    return block->values[index] == block->count - 1;
}
