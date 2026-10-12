extern "C" void* function_794276(void* destination, const void* source, unsigned long long size);

struct block_3e7aec {
    unsigned char reserved0[0x88];
    unsigned char region[0x9E8];
};

extern "C" char function_3e7aec(block_3e7aec* block, const void* source) {
    function_794276(block->region, source, sizeof(block->region));
    return 1;
}
