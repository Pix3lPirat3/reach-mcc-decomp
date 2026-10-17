extern "C" char function_32f0d4(char *object, int, char *object2) {
    long long local1;
    long long local2;
    long long local3;
    short local4;
    local1 = *(unsigned long long *)(object + 112);
    local2 = 0;
    if (local1 && *(unsigned char *)(object + 40) == 2) {
        local3 = *(int *)(object + 124);
        if ((int)local3 >= 0 && (int)local3 < *(int *)(local1 + 0x1E1CC)) {
            local4 = *(unsigned short *)(local1 + local3 * 4 + 0x1E1D2);
            if (-1 != local4) {
                local2 = local1 + 0x1C0CC + (long long)local4 * 0x210;
            }
        }
    }
    *(unsigned int *)object2 = 3;
    *(unsigned long long *)(object2 + 8) = local2;
    return 1;
}
