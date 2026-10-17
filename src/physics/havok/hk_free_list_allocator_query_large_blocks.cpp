struct free_list_allocator {
    unsigned char reserved0[0x48];
    unsigned char large_blocks[1];
};

extern "C" int function_878380(void* large_blocks);

extern "C" int function_86f210(free_list_allocator* allocator) {
    return function_878380(allocator->large_blocks);
}
