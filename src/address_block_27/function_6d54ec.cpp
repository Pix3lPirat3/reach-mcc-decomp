struct flag_holder {
    unsigned char reserved0[0x2F];
    unsigned char field_2f;
};

extern "C" short function_6d54ec(long long, flag_holder* holder) {
    return holder->field_2f != 0 ? 0x7F : -2;
}
