struct state_block {
    unsigned char reserved0[0x1B464];
    int current;
    unsigned char reserved1B468[0xE014];
    int count;
};

extern "C" char function_3e4ea4(state_block* block) {
    int count = block->count;
    if (count == -1)
        return 0;
    if (block->current >= count - 1)
        return 0;
    return 1;
}
