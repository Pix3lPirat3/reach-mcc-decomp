struct bignum {
    void* digits;
    int reserved8;
    int top;
    int dmax;
    int flags;
};

extern "C" int BN_with_flags_7a6530(bignum* dest, bignum* source, int flags) {
    dest->digits = source->digits;
    dest->reserved8 = source->reserved8;
    dest->top = source->top;
    dest->dmax = source->dmax;
    int kept = dest->flags & 1;
    dest->flags = source->flags & -2 | kept | flags | 2;
    return kept;
}
