extern "C" long long function_66618(long long value, int value2, char value3) {
    int local1;
    long long local2;
    local1 = *(unsigned char *)value;
    if (value3 != 0) {
        local2 = (unsigned int)(local1 | 1 << value2);
    } else {
        local2 = (unsigned int)(local1 & ~(1 << value2));
    }
    *(unsigned char *)value = (unsigned char)(local2);
    return local2;
}
