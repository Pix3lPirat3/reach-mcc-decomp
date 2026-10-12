extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_3e76c0 {
    unsigned char reserved0[0x88];
    unsigned char region[0x70];
};

extern "C" void* function_3e76c0(block_3e76c0* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
