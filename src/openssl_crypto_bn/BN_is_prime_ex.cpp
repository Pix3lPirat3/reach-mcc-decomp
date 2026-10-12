typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;
typedef struct bn_gencb_st BN_GENCB;
int BN_is_prime_ex(const BIGNUM *p, int nchecks, BN_CTX *ctx, BN_GENCB *cb);
int BN_is_prime_fasttest_ex(const BIGNUM *p, int nchecks, BN_CTX *ctx,
                            int do_trial_division, BN_GENCB *cb);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
struct bn_gencb_st {
    unsigned int ver;
    void *arg;
    union {
        void (*cb_1) (int, int, void *);
        int (*cb_2) (int, int, BN_GENCB *);
    } cb;
};
int BN_is_prime_ex(const BIGNUM *a, int checks, BN_CTX *ctx_passed,
                   BN_GENCB *cb)
{
    return BN_is_prime_fasttest_ex(a, checks, ctx_passed, 0, cb);
}
