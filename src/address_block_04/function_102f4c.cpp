extern "C" void * function_35c3c(void* destination, const void* source, unsigned long long length);
extern "C" void * function_78932a(void* destination, int value, unsigned long long length);

extern "C" void * function_102f4c(unsigned char* header, const void* description) {
    function_78932a(header + 0x180, 0, 0x100);
    return function_35c3c(header + 0x180, description, 0x80);
}
