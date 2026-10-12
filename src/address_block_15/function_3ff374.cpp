extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_3ff374 {
    unsigned char reserved0[0x88];
    unsigned char region[0x220];
};

extern "C" void* function_3ff374(block_3ff374* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
