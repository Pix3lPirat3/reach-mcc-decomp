extern "C" long long function_eaa8c(void *object, int value, unsigned int value2, char value3) {
    long long local1;
    int local2;
    int local3;
    unsigned long long local4;
    local1 = (long long)value * 0x34;
    local2 = 1 << value2;
    local3 = *(unsigned int *)(local1 + (char *)object + 0x748);
    if (value3 != 0) {
        local4 = (unsigned int)(local2 | local3);
    } else {
        local4 = (unsigned int)(~local2 & local3);
    }
    *(unsigned int *)(local1 + (char *)object + 0x748) = (unsigned int)(local4);
    return local4;
}
