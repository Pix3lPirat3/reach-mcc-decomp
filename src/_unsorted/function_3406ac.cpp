extern "C" char function_3406ac(char *object, int, char *object2) {
    int local1 = 0;
    if (*(unsigned int *)(object + 116) == 2) {
        local1 = *(unsigned int *)(object + 0x3A58) <= 1 ? *(unsigned int *)(object + 0x3A50) : *(unsigned int *)(object + 0x3A08);
    }
    *(unsigned int *)(object2 + 8) = local1;
    *(unsigned int *)object2 = 1;
    return 1;
}
