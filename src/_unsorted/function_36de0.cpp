extern "C" char function_36de0(long long value, int value2, void* value3) {
    if (value2 == 1) {
        *(unsigned long long *)value3 = value;
        return (char)(value2);
    }
    *(unsigned long long *)value3 = 0;
    return 0;
}
