extern "C" int function_cde00(unsigned char* object) {
    return ((*(unsigned int*)(object + 0x10) + 0x1F) >> 5) * 4 + 3;
}
