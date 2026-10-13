typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;
void BN_CTX_start(BN_CTX *ctx);
BIGNUM *BN_CTX_get(BN_CTX *ctx);
void BN_CTX_end(BN_CTX *ctx);
int BN_GF2m_mod_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                    const BIGNUM *p, BN_CTX *ctx);
int BN_GF2m_mod_inv(BIGNUM *r, const BIGNUM *b, const BIGNUM *p, BN_CTX *ctx);
int BN_GF2m_mod_div(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
                    const BIGNUM *p, BN_CTX *ctx);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
int BN_GF2m_mod_div(BIGNUM *r, const BIGNUM *y, const BIGNUM *x,
                    const BIGNUM *p, BN_CTX *ctx)
{
    BIGNUM *xinv = ((void *)0);
    int ret = 0;
    ;
    ;
    ;
    BN_CTX_start(ctx);
    xinv = BN_CTX_get(ctx);
    if (xinv == ((void *)0))
        goto err;
    if (!BN_GF2m_mod_inv(xinv, x, p, ctx))
        goto err;
    if (!BN_GF2m_mod_mul(r, y, xinv, p, ctx))
        goto err;
    ;
    ret = 1;
 err:
    BN_CTX_end(ctx);
    return ret;
}
