extern "C" void * function_3e8bd8(void* block);
extern "C" void * function_78932a(void* destination, int value, unsigned long long size);

extern "C" void * function_3e4b64(unsigned char* block) {
    function_3e8bd8(block);
    return function_78932a(block + 0x88, 0, 0x1F810);
}
