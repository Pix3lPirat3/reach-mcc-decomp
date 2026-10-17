extern "C" void* function_78932a(void* destination, int value, unsigned long long size);

struct block_3e8898 {
    unsigned char reserved0[0x490];
    unsigned char region[0x408];
};

extern "C" void* function_3e8898(block_3e8898* block) {
    return function_78932a(block->region, 0, sizeof(block->region));
}
