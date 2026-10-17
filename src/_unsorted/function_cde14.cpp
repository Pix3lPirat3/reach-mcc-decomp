extern "C" long long function_cde14(unsigned char* object, unsigned char* allocator) {
    int bit_count = *(int*)(object + 0x10);
    long long start = 0;
    long long words = (unsigned int)(bit_count + 0x1F) >> 5;
    if (words != 0) {
        start = *(long long*)(allocator + 0x10) + 3 & -4;
        *(long long*)(allocator + 0x10) = start + words * 4;
        bit_count = *(int*)(object + 0x10);
    }
    long long result = *(long long*)(object + 8);
    *(long long*)result = start;
    *(int*)(result + 8) = bit_count;
    return result;
}
