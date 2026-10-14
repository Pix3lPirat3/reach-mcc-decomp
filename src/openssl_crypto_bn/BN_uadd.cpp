__pragma(warning(disable: 4244))
typedef struct bignum_st BIGNUM;
int BN_uadd(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
BIGNUM *bn_wexpand(BIGNUM *a, int words);
unsigned long long bn_add_words(unsigned long long *rp, const unsigned long long *ap, const unsigned long long *bp,
                      int num);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
int BN_uadd(BIGNUM *r, const BIGNUM *a, const BIGNUM *b)
{
    int max, min, dif;
    const unsigned long long *ap, *bp;
    unsigned long long *rp, carry, t1, t2;
    ;
    ;
    if (a->top < b->top) {
        const BIGNUM *tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    max = a->top;
    min = b->top;
    dif = max - min;
    if (bn_wexpand(r, max + 1) == ((void *)0))
        return 0;
    r->top = max;
    ap = a->d;
    bp = b->d;
    rp = r->d;
    carry = bn_add_words(rp, ap, bp, min);
    rp += min;
    ap += min;
    while (dif) {
        dif--;
        t1 = *(ap++);
        t2 = (t1 + carry) & (0xffffffffffffffffLL);
        *(rp++) = t2;
        carry &= (t2 == 0);
    }
    *rp = carry;
    r->top += carry;
    r->neg = 0;
    ;
    return 1;
}
