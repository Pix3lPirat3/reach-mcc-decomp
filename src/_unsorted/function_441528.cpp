extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_441528 {
    unsigned char reserved0[0x1DC];
    unsigned char region[0x154];
};

extern "C" void* function_441528(block_441528* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
