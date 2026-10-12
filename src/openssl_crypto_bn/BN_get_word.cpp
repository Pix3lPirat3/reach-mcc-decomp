__pragma(warning(disable: 4245))
typedef struct bignum_st BIGNUM;
unsigned long long BN_get_word(const BIGNUM *a);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
unsigned long long BN_get_word(const BIGNUM *a)
{
    if (a->top > 1)
        return (0xffffffffffffffffLL);
    else if (a->top == 1)
        return a->d[0];
    return 0;
}
