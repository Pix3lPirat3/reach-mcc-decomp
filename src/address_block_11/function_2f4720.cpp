extern "C" unsigned long long function_2f4720(long long value, int value2) {
    return value2 < 0 ? 0 : value2 >= *(int *)(value + 0x110) ? 0 : *(unsigned long long *)(value + (long long)value2 * 8 + 16);
}
