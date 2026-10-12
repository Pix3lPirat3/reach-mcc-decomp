struct big_number {
    unsigned long long* field_0;
    int field_8;
    int field_c;
    int field_10;
};

extern "C" int BN_is_one_7a5f60(big_number* number) {
    if (number->field_8 != 1)
        return 0;
    if (number->field_0[0] != 1)
        return 0;
    if (number->field_10 != 0)
        return 0;
    return 1;
}
