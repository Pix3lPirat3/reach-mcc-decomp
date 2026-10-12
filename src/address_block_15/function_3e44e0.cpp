struct state_block {
    unsigned char reserved0[0x1F898];
    int values[0x1416];
    int count;
};

extern "C" char function_3e44e0(state_block* block, int index) {
    return block->values[index] == block->count - 1;
}
