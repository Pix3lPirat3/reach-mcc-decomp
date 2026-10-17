struct state_block {
    unsigned char reserved0[0x88];
    unsigned char bytes[1];
};

extern "C" void * function_78932a(void* destination, int value, unsigned long long size);

extern "C" void * function_3e58f0(state_block* block) {
    return function_78932a(block->bytes, 0, 0x120);
}
