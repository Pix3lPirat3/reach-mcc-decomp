typedef struct bignum_st BIGNUM;
int BN_mask_bits(BIGNUM *a, int n);
void bn_correct_top(BIGNUM *a);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
int BN_mask_bits(BIGNUM *a, int n)
{
    int b, w;
    ;
    if (n < 0)
        return 0;
    w = n / (8 * 8);
    b = n % (8 * 8);
    if (w >= a->top)
        return 0;
    if (b == 0)
        a->top = w;
    else {
        a->top = w + 1;
        a->d[w] &= ~((0xffffffffffffffffLL) << b);
    }
    bn_correct_top(a);
    return 1;
}
void bn_correct_top(BIGNUM *a)
{
    unsigned long long *ftl;
    int tmp_top = a->top;
    if (tmp_top > 0) {
        for (ftl = &(a->d[tmp_top]); tmp_top > 0; tmp_top--) {
            ftl--;
            if (*ftl != 0)
                break;
        }
        a->top = tmp_top;
    }
    if (a->top == 0)
        a->neg = 0;
    a->flags &= ~0;
    ;
}
