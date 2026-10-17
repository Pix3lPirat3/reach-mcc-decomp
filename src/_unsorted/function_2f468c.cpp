extern "C" unsigned long long function_2f468c(long long value, int value2) {
    return value2 < 0 ? 0 : value2 >= *(int *)(value + 0x810) ? 0 : *(unsigned long long *)(value + (long long)value2 * 8 + 16);
}
