extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_3e7ab8 {
    unsigned char reserved0[0xA70];
    unsigned char region[0x9E8];
};

extern "C" void* function_3e7ab8(block_3e7ab8* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
