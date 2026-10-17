extern "C" long long function_3e655c(unsigned char* block) {
    *(__unaligned long long*)(block + 0x9C) = 0;
    *(__unaligned long long*)(block + 0xA4) = 0;
    *(__unaligned int*)(block + 0xAC) = 0;
    return 0;
}
