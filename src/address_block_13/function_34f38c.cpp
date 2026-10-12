extern "C" char function_34f38c(char *object, long long, char *object2) {
    long long local1;
    long long local2;
    long long local3;
    local1 = *(unsigned long long *)(object + 0x50);
    local2 = 0;
    local3 = local1 != 0 ? *(unsigned long long *)(local1 + 0x58) : local2;
    if (local3 != 0) {
        local2 = *(unsigned int *)(local3 + 0x60);
    }
    *(unsigned int *)(object2 + 8) = (unsigned int)(local2);
    *(unsigned int *)object2 = 1;
    return 1;
}
