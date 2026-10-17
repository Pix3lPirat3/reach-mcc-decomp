struct flag_holder {
    unsigned char reserved0[0xF861];
    unsigned char flag;
};

extern "C" char function_e2384(flag_holder* holder, unsigned int value) {
    holder->flag = value <= 1 ? (unsigned char)value : 0;
    return (unsigned char)value;
}
