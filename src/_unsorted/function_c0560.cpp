extern "C" bool function_c0560(long long, unsigned char* left, long long, unsigned char* right) {
    int value = *(int*)(left + 0x24);
    if (value == -1)
        return false;
    if (*(int*)(right + 0x24) == -1)
        return false;
    if (value != *(int*)(right + 0x24))
        return false;
    return true;
}
