extern "C" void* function_794276(void* destination, const void* source, unsigned long long size);

struct block_3e6f9c {
    unsigned char reserved0[0x88];
    unsigned char region[0x8D8];
};

extern "C" char function_3e6f9c(block_3e6f9c* block, const void* source) {
    function_794276(block->region, source, sizeof(block->region));
    return 1;
}
