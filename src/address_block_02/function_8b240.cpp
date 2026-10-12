extern "C" long long function_8b240(unsigned char* object) {
    if (*(long long*)(object + 0x480) != 0)
        *(long long*)(object + 0x480) = 0;
    if (*(long long*)(object + 0x458) == 0)
        return 0;
    *(long long*)(object + 0x458) = 0;
    return 0;
}
