struct big_number {
    unsigned char reserved0[8];
    int field_8;
    unsigned char reservedc[4];
    int field_10;
};

extern "C" int BN_zero_ex_7a6560(big_number* number) {
    number->field_10 = 0;
    number->field_8 = 0;
    return 0;
}
