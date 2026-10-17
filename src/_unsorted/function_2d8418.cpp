extern "C" int function_2d8418(long long value, long long value2) {
    int local1;
    int local2;
    if (*(unsigned char *)value) {
        if (!*(unsigned char *)value2) {
            return -1;
        }
        if (*(int *)(value + 8) > *(int *)(value2 + 8)) {
            return -1;
        }
        if (*(int *)(value + 8) < *(int *)(value2 + 8)) {
            return 1;
        }
        local2 = *(unsigned int *)(value + 16);
        local1 = *(unsigned int *)(value2 + 16);
        if (local2 < local1) {
            return -1;
        }
        return local2 > local1;
    }
    return *(unsigned char *)value2 != 0;
}
