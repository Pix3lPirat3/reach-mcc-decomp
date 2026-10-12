extern "C" int function_1c17b0(long long value, short value2) {
    long long local1;
    int local2;
    if (-1 == value2) {
        return -1;
    }
    local1 = (unsigned int)value2 >> 5;
    local2 = (int)(1 << (value2 & 0x1F));
    *(unsigned int *)(value + local1 * 4 + 8) = *(unsigned int *)(value + local1 * 4 + 8) | local2;
    return (local2);
}
