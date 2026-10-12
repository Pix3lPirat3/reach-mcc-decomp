extern "C" long long function_794276(void* destination, void* source, long long size);

extern "C" char function_3e4144(unsigned char* block, void* source) {
    function_794276(block + 0x88, source, 0xA78);
    return 1;
}
