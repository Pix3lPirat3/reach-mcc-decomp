extern "C" int function_6af34(long long value, unsigned int value2) {
    long long result = 0;
    if (value2 < 12) {
        result = ((long long)value2 << 6) + *(unsigned long long *)(value + 8);
    }
    return (int)(result);
}
