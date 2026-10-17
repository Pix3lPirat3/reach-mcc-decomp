extern "C" bool function_2f3a88(long long value, long long value2) {
    long long local1;
    if (*(unsigned int *)value != 0) {
        if (*(unsigned int *)value != 2) {
            if (*(unsigned int *)value != 6) {
                return 0;
            }
            local1 = *(unsigned int *)(value + 8);
            *(unsigned int *)(value2 + 8) = (int)local1;
            *(unsigned int *)value2 = 1;
            return 1;
        }
        local1 = (unsigned int)(int)*(float *)(value + 8);
        *(unsigned int *)(value2 + 8) = (int)local1;
        *(unsigned int *)value2 = 1;
        return 1;
    }
    local1 = *(unsigned char *)(value + 8) != 0;
    *(unsigned int *)(value2 + 8) = (unsigned int)(local1);
    *(unsigned int *)value2 = 1;
    return 1;
}
