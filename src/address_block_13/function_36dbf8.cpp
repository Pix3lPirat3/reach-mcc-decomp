extern "C" char function_36dbf8(char *object, int, char *object2) {
    int local1;
    char local2;
    char local3;
    local2 = *(unsigned char *)(object2 + 8);
    local1 = *(unsigned char *)(object + 120);
    local3 = (char)(local2 == 0 ? local1 & -65 : local1 | 64);
    *(unsigned char *)(object + 120) = local2 == (char)(local1 >> 6 & 1) ? local3 & 127 : local3 | -128;
    return 1;
}
