extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_3e6f68 {
    unsigned char reserved0[0x960];
    unsigned char region[0x8D8];
};

extern "C" void* function_3e6f68(block_3e6f68* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
