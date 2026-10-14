typedef struct bignum_st BIGNUM;
int BN_ucmp(const BIGNUM *a, const BIGNUM *b);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
int BN_ucmp(const BIGNUM *a, const BIGNUM *b)
{
    int i;
    unsigned long long t1, t2, *ap, *bp;
    ;
    ;
    i = a->top - b->top;
    if (i != 0)
        return i;
    ap = a->d;
    bp = b->d;
    for (i = a->top - 1; i >= 0; i--) {
        t1 = ap[i];
        t2 = bp[i];
        if (t1 != t2)
            return ((t1 > t2) ? 1 : -1);
    }
    return 0;
}
