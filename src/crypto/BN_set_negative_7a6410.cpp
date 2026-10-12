struct big_number {
    unsigned char reserved0[8];
    int field_8;
    unsigned char reservedc[4];
    int field_10;
};

extern "C" void BN_set_negative_7a6410(big_number* number, int negative) {
    if (negative == 0 || number->field_8 == 0) {
        number->field_10 = 0;
        return;
    }
    number->field_10 = 1;
}
