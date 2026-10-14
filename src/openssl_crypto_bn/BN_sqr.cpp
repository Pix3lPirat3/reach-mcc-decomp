typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;
int BN_sqr(BIGNUM *r, const BIGNUM *a, BN_CTX *ctx);
void bn_correct_top(BIGNUM *a);
int bn_sqr_fixed_top(BIGNUM *r, const BIGNUM *a, BN_CTX *ctx);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
int BN_sqr(BIGNUM *r, const BIGNUM *a, BN_CTX *ctx)
{
    int ret = bn_sqr_fixed_top(r, a, ctx);
    bn_correct_top(r);
    ;
    return ret;
}
