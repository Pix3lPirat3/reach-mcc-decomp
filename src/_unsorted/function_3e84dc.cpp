extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_3e84dc {
    unsigned char reserved0[0xD4];
    unsigned char region[0x4C];
};

extern "C" void* function_3e84dc(block_3e84dc* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
