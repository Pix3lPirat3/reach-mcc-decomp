extern "C" long long function_78932a(long long dest, long long value, long long size);

extern "C" long long function_1790c8(unsigned char* object) {
    *(int*)(object + 0x100) = 0;
    function_78932a((long long)object, 0, 0x100);
    return (long long)object;
}
