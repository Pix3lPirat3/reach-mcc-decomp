struct time_holder {
    unsigned char reserved0[0x7E4];
    unsigned short limit;
};

extern "C" long long function_eab70(time_holder* holder, unsigned short value) {
    holder->limit = value;
    if (value <= 0xE10)
        return 0xE10;
    holder->limit = 0;
    return 0;
}
