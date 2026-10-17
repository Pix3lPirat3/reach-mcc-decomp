extern "C" bool function_32aee4(int value, int value2, char *object3) {
    short local2;
    short local1 = *(unsigned short *)(object3 + (value + (long long)value * 2) * 4 + 0x302);
    local2 = *(unsigned short *)(object3 + (value2 + (long long)value2 * 2) * 4 + 0x302) & 0x7FFF;
    if ((unsigned short)(local1 & 0x7FFF) > (local2 & 0xFFFF)) {
        return 0;
    }
    if ((local1 & 0x7FFF) < local2) {
        return 1;
    }
    if (value > value2) {
        return 0;
    }
    return 1;
}
