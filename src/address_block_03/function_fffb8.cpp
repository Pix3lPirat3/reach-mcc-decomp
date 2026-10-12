extern "C" char function_fffb8(int value, int value2, long long value3) {
    return *(float *)(value3 + (long long)value * 4) < *(float *)(value3 + (long long)value2 * 4);
}
