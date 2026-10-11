struct bignum {
    unsigned long long* digits;
    int top;
    int dmax;
    int neg;
    int flags;
};

extern "C" int BN_is_negative_7a5f30(const bignum* number) {
    return number->neg != 0;
}
