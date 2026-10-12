extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_3e76d4 {
    unsigned char reserved0[0xC0];
    unsigned char region[0x38];
};

extern "C" void* function_3e76d4(block_3e76d4* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
