extern "C" char function_2292a4(int value, int value2, long long value3) {
    char local4;
    long long local1;
    long long local2;
    char local3;
    local1 = (long long)value * 30;
    local2 = (long long)value2 * 30;
    local3 = *(unsigned char *)(local1 + value3 + 0xD36);
    local4 = *(unsigned char *)(local2 + value3 + 0xD36);
    if (local3 != local4) {
        return local3 > local4;
    }
    return *(unsigned char *)(local1 + value3 + 0xD37) > *(unsigned char *)(local2 + value3 + 0xD37);
}
