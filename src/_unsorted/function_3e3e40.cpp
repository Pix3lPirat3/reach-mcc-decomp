struct state_block {
    unsigned char reserved0[0x88];
    long long first;
    long long second;
    long long third;
};

extern "C" long long function_3e3e40(state_block* block) {
    block->first = 0;
    block->second = 0;
    block->third = 0;
    return 0;
}
