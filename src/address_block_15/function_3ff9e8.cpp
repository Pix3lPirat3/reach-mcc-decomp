extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_3ff9e8 {
    unsigned char reserved0[0x198];
    unsigned char region[0x110];
};

extern "C" void* function_3ff9e8(block_3ff9e8* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
