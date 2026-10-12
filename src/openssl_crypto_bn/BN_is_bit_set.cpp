typedef struct bignum_st BIGNUM;
int BN_is_bit_set(const BIGNUM *a, int n);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
int BN_is_bit_set(const BIGNUM *a, int n)
{
    int i, j;
    ;
    if (n < 0)
        return 0;
    i = n / (8 * 8);
    j = n % (8 * 8);
    if (a->top <= i)
        return 0;
    return (int)(((a->d[i]) >> j) & ((unsigned long long)1));
}
