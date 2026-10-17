extern "C" int function_cd3f4(unsigned int value, long long value2) {
    return value < *(unsigned int *)value2 ? -1 : value > *(unsigned int *)(value2 + 4);
}
