struct state_block {
    unsigned char reserved0[0xA0];
    long long first;
    long long second;
    long long third;
};

extern "C" long long function_3e4090(state_block* block) {
    block->first = 0;
    block->second = 0;
    block->third = 0;
    return 0;
}
