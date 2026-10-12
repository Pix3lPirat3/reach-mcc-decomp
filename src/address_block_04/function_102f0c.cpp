extern "C" void * function_78932a(void* destination, int value, unsigned long long size);
extern "C" void* function_35c3c(void* destination, void* source, unsigned long long size);

extern "C" void* function_102f0c(char* header, void* name) {
    function_78932a(header + 0x80, 0, 0x100);
    return function_35c3c(header + 0x80, name, 0x80);
}
