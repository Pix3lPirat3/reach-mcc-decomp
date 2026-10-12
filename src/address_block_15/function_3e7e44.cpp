extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_3e7e44 {
    unsigned char reserved0[0x184];
    unsigned char region[0xFC];
};

extern "C" void* function_3e7e44(block_3e7e44* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
