extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_3e7350 {
    unsigned char reserved0[0xFC];
    unsigned char region[0x74];
};

extern "C" void* function_3e7350(block_3e7350* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
