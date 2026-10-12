typedef struct bignum_st BIGNUM;
int BN_GF2m_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b);
BIGNUM *bn_wexpand(BIGNUM *a, int words);
void bn_correct_top(BIGNUM *a);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
int BN_GF2m_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b)
{
    int i;
    const BIGNUM *at, *bt;
    ;
    ;
    if (a->top < b->top) {
        at = b;
        bt = a;
    } else {
        at = a;
        bt = b;
    }
    if (bn_wexpand(r, at->top) == ((void *)0))
        return 0;
    for (i = 0; i < bt->top; i++) {
        r->d[i] = at->d[i] ^ bt->d[i];
    }
    for (; i < at->top; i++) {
        r->d[i] = at->d[i];
    }
    r->top = at->top;
    bn_correct_top(r);
    return 1;
}
