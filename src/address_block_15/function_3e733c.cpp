extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_3e733c {
    unsigned char reserved0[0x88];
    unsigned char region[0xE8];
};

extern "C" void* function_3e733c(block_3e733c* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
