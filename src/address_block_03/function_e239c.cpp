struct limit_holder {
    unsigned char reserved0[0xF862];
    unsigned short limit;
};

extern "C" long long function_e239c(limit_holder* holder, unsigned short value) {
    holder->limit = value > 0x3C ? 5 : value;
    return 5;
}
