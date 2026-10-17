extern "C" long long function_1790b4(unsigned char* object) {
    *(long long*)(object + 2) = 0x3F800000;
    *(unsigned short*)object = 0;
    *(int*)(object + 0xA) = 0;
    return (long long)object;
}
