typedef struct bignum_st BIGNUM;
int BN_cmp(const BIGNUM *a, const BIGNUM *b);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
int BN_cmp(const BIGNUM *a, const BIGNUM *b)
{
    int i;
    int gt, lt;
    unsigned long long t1, t2;
    if ((a == ((void *)0)) || (b == ((void *)0))) {
        if (a != ((void *)0))
            return -1;
        else if (b != ((void *)0))
            return 1;
        else
            return 0;
    }
    ;
    ;
    if (a->neg != b->neg) {
        if (a->neg)
            return -1;
        else
            return 1;
    }
    if (a->neg == 0) {
        gt = 1;
        lt = -1;
    } else {
        gt = -1;
        lt = 1;
    }
    if (a->top > b->top)
        return gt;
    if (a->top < b->top)
        return lt;
    for (i = a->top - 1; i >= 0; i--) {
        t1 = a->d[i];
        t2 = b->d[i];
        if (t1 > t2)
            return gt;
        if (t1 < t2)
            return lt;
    }
    return 0;
}
