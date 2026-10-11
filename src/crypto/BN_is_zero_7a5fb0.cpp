struct bignum {
    unsigned long long* digits;
    int top;
    int dmax;
    int neg;
    int flags;
};

extern "C" int BN_is_zero_7a5fb0(const bignum* number) {
    return number->top == 0;
}
