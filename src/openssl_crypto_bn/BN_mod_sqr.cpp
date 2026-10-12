typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;
int BN_sqr(BIGNUM *r, const BIGNUM *a, BN_CTX *ctx);
int BN_div(BIGNUM *dv, BIGNUM *rem, const BIGNUM *m, const BIGNUM *d,
           BN_CTX *ctx);
int BN_mod_sqr(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
int BN_mod_sqr(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx)
{
    if (!BN_sqr(r, a, ctx))
        return 0;
    return BN_div(((void *)0),(r),(r),(m),(ctx));
}
