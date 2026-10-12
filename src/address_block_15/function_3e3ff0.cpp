extern "C" long long function_3e3ff0(unsigned char* block) {
    *(__unaligned long long*)(block + 0xA4) = 0;
    *(__unaligned long long*)(block + 0xAC) = 0;
    *(__unaligned long long*)(block + 0xB4) = 0;
    *(__unaligned int*)(block + 0xBC) = 0;
    return 0;
}
