struct big_number {
    unsigned long long* field_0;
    int field_8;
};

extern "C" int BN_abs_is_word_7a5840(big_number* number, unsigned long long word) {
    int count = number->field_8;
    if (count != 1 || number->field_0[0] != word) {
        if (word != 0)
            return 0;
        if (count != 0)
            return 0;
        return 1;
    }
    return 1;
}
