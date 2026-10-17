extern "C" unsigned int function_7373cc(char *object, char *object2) {
    float local2;
    float local1;
    local1 = *(float *)(object + 8);
    local2 = *(float *)(object2 + 8);
    if (local1 > local2) {
        return 0xFFFFFFFF;
    }
    if (local2 > local1 || *(unsigned int *)(object + 12) == -1 || *(unsigned int *)(object2 + 12) != -1) {
        return 1;
    } else {
        return 0xFFFFFFFF;
    }
}
