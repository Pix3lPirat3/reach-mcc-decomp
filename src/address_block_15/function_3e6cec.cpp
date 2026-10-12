extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_3e6cec {
    unsigned char reserved0[0xCA0];
    unsigned char region[0xC18];
};

extern "C" void* function_3e6cec(block_3e6cec* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
