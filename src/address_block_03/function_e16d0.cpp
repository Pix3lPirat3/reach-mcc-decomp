extern "C" char function_e16d0(unsigned char* first, unsigned char* second) {
    *(int*)(first + 0x31C) = 0;
    *(int*)(second + 0x31C) = 0;
    return 1;
}
