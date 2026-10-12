extern "C" long long function_2d0600(long long value, char value2) {
    long long local1;
    int local2;
    int local3;
    long long local4;
    local1 = *(unsigned long long *)(value + 0x18);
    local3 = *(unsigned char *)local1;
    local2 = *(unsigned int *)(value + 0x20);
    if (value2 != 0) {
        local4 = (unsigned int)(local3 | 1 << local2);
    } else {
        local4 = (unsigned int)(local3 & ~(1 << local2));
    }
    *(unsigned char *)local1 = (unsigned char)(local4);
    return local4;
}
