struct state_block {
    unsigned char reserved0[0x1F8E4];
    int current;
    unsigned char reserved1F8E8[0xA014];
    int count;
};

extern "C" char function_3e450c(state_block* block) {
    int count = block->count;
    if (count == -1)
        return 0;
    if (block->current >= count - 1)
        return 0;
    return 1;
}
