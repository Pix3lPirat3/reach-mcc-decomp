typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;
typedef struct bn_recp_ctx_st BN_RECP_CTX;
void BN_CTX_start(BN_CTX *ctx);
BIGNUM *BN_CTX_get(BN_CTX *ctx);
void BN_CTX_end(BN_CTX *ctx);
int BN_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_CTX *ctx);
int BN_sqr(BIGNUM *r, const BIGNUM *a, BN_CTX *ctx);
int BN_mod_mul_reciprocal(BIGNUM *r, const BIGNUM *x, const BIGNUM *y,
                          BN_RECP_CTX *recp, BN_CTX *ctx);
int BN_div_recp(BIGNUM *dv, BIGNUM *rem, const BIGNUM *m,
                BN_RECP_CTX *recp, BN_CTX *ctx);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
struct bn_recp_ctx_st {
    BIGNUM N;
    BIGNUM Nr;
    int num_bits;
    int shift;
    int flags;
};
int BN_mod_mul_reciprocal(BIGNUM *r, const BIGNUM *x, const BIGNUM *y,
                          BN_RECP_CTX *recp, BN_CTX *ctx)
{
    int ret = 0;
    BIGNUM *a;
    const BIGNUM *ca;
    BN_CTX_start(ctx);
    if ((a = BN_CTX_get(ctx)) == ((void *)0))
        goto err;
    if (y != ((void *)0)) {
        if (x == y) {
            if (!BN_sqr(a, x, ctx))
                goto err;
        } else {
            if (!BN_mul(a, x, y, ctx))
                goto err;
        }
        ca = a;
    } else
        ca = x;
    ret = BN_div_recp(((void *)0), r, ca, recp, ctx);
 err:
    BN_CTX_end(ctx);
    ;
    return ret;
}
