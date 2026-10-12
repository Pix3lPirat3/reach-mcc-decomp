typedef struct bignum_st BIGNUM;
int BN_abs_is_word(const BIGNUM *a, const unsigned long long w);
int BN_is_word(const BIGNUM *a, const unsigned long long w);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
int BN_abs_is_word(const BIGNUM *a, const unsigned long long w)
{
    return ((a->top == 1) && (a->d[0] == w)) || ((w == 0) && (a->top == 0));
}
int BN_is_word(const BIGNUM *a, const unsigned long long w)
{
    return BN_abs_is_word(a, w) && (!w || !a->neg);
}
