extern "C" char function_3629ac(char *object, int, char *object2) {
    long long local1;
    int local2 = 0;
    local1 = *(unsigned long long *)(object + 112);
    if (local1) {
        local2 = *(unsigned int *)(local1 + 0x274) + 1;
    }
    *(unsigned int *)object2 = 1;
    *(unsigned int *)(object2 + 8) = local2;
    return 1;
}
