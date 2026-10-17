extern "C" char function_306390(char *object, int, char *object2) {
    long long local1;
    int local2;
    local1 = *(unsigned long long *)(object + 0x160);
    local2 = local1 ? *(unsigned int *)(local1 + 0x148) : -1;
    *(unsigned int *)(object2 + 8) = local2;
    *(unsigned int *)object2 = 6;
    return 1;
}
