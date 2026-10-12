typedef int                int32_t;
typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;
typedef struct bn_mont_ctx_st BN_MONT_CTX;
typedef struct bn_gencb_st BN_GENCB;
typedef struct dh_st DH;
typedef struct dh_method DH_METHOD;
typedef struct engine_st ENGINE;
typedef struct crypto_ex_data_st CRYPTO_EX_DATA;
typedef void CRYPTO_RWLOCK;
struct crypto_ex_data_st {
    struct stack_st_void *sk;
};
struct stack_st_void;
void ERR_put_error(int lib, int func, int reason, const char *file, int line);
void BN_set_flags(BIGNUM *b, int n);
void BN_with_flags(BIGNUM *dest, const BIGNUM *b, int flags);
int BN_is_zero(const BIGNUM *a);
int BN_is_one(const BIGNUM *a);
BN_CTX *BN_CTX_new(void);
void BN_CTX_free(BN_CTX *c);
void BN_CTX_start(BN_CTX *ctx);
BIGNUM *BN_CTX_get(BN_CTX *ctx);
void BN_CTX_end(BN_CTX *ctx);
int BN_priv_rand(BIGNUM *rnd, int bits, int top, int bottom);
int BN_priv_rand_range(BIGNUM *rnd, const BIGNUM *range);
int BN_num_bits(const BIGNUM *a);
BIGNUM *BN_new(void);
BIGNUM *BN_secure_new(void);
int BN_bn2bin(const BIGNUM *a, unsigned char *to);
void BN_free(BIGNUM *a);
BN_MONT_CTX *BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont, CRYPTO_RWLOCK *lock,
                                    const BIGNUM *mod, BN_CTX *ctx);
int DH_check_pub_key(const DH *dh, const BIGNUM *pub_key, int *codes);
int DH_generate_key(DH *dh);
typedef volatile int CRYPTO_REF_COUNT;
struct dh_st {
    int pad;
    int version;
    BIGNUM *p;
    BIGNUM *g;
    int32_t length;
    BIGNUM *pub_key;
    BIGNUM *priv_key;
    int flags;
    BN_MONT_CTX *method_mont_p;
    BIGNUM *q;
    BIGNUM *j;
    unsigned char *seed;
    int seedlen;
    BIGNUM *counter;
    CRYPTO_REF_COUNT references;
    CRYPTO_EX_DATA ex_data;
    const DH_METHOD *meth;
    ENGINE *engine;
    CRYPTO_RWLOCK *lock;
};
struct dh_method {
    char *name;
    int (*generate_key) (DH *dh);
    int (*compute_key) (unsigned char *key, const BIGNUM *pub_key, DH *dh);
    int (*bn_mod_exp) (const DH *dh, BIGNUM *r, const BIGNUM *a,
                       const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx,
                       BN_MONT_CTX *m_ctx);
    int (*init) (DH *dh);
    int (*finish) (DH *dh);
    int flags;
    char *app_data;
    int (*generate_params) (DH *dh, int prime_len, int generator,
                            BN_GENCB *cb);
};
static int generate_key(DH *dh);
static int compute_key(unsigned char *key, const BIGNUM *pub_key, DH *dh);
int DH_generate_key(DH *dh)
{
    return dh->meth->generate_key(dh);
}
static int generate_key(DH *dh)
{
    int ok = 0;
    int generate_new_key = 0;
    unsigned l;
    BN_CTX *ctx = ((void *)0);
    BN_MONT_CTX *mont = ((void *)0);
    BIGNUM *pub_key = ((void *)0), *priv_key = ((void *)0);
    if (BN_num_bits(dh->p) > 10000) {
        ERR_put_error(5,(103),(103),"crypto\\dh\\dh_key.c",86);
        return 0;
    }
    ctx = BN_CTX_new();
    if (ctx == ((void *)0))
        goto err;
    if (dh->priv_key == ((void *)0)) {
        priv_key = BN_secure_new();
        if (priv_key == ((void *)0))
            goto err;
        generate_new_key = 1;
    } else
        priv_key = dh->priv_key;
    if (dh->pub_key == ((void *)0)) {
        pub_key = BN_new();
        if (pub_key == ((void *)0))
            goto err;
    } else
        pub_key = dh->pub_key;
    if (dh->flags & 0x01) {
        mont = BN_MONT_CTX_set_locked(&dh->method_mont_p,
                                      dh->lock, dh->p, ctx);
        if (!mont)
            goto err;
    }
    if (generate_new_key) {
        if (dh->q) {
            do {
                if (!BN_priv_rand_range(priv_key, dh->q))
                    goto err;
            }
            while (BN_is_zero(priv_key) || BN_is_one(priv_key));
        } else {
            l = dh->length ? dh->length : BN_num_bits(dh->p) - 1;
            if (!BN_priv_rand(priv_key, l, 0, 0))
                goto err;
        }
    }
    {
        BIGNUM *prk = BN_new();
        if (prk == ((void *)0))
            goto err;
        BN_with_flags(prk, priv_key, 0x04);
        if (!dh->meth->bn_mod_exp(dh, pub_key, dh->g, prk, dh->p, ctx, mont)) {
            BN_free(prk);
            goto err;
        }
        BN_free(prk);
    }
    dh->pub_key = pub_key;
    dh->priv_key = priv_key;
    ok = 1;
 err:
    if (ok != 1)
        ERR_put_error(5,(103),(3),"crypto\\dh\\dh_key.c",151);
    if (pub_key != dh->pub_key)
        BN_free(pub_key);
    if (priv_key != dh->priv_key)
        BN_free(priv_key);
    BN_CTX_free(ctx);
    return ok;
}
static int compute_key(unsigned char *key, const BIGNUM *pub_key, DH *dh)
{
    BN_CTX *ctx = ((void *)0);
    BN_MONT_CTX *mont = ((void *)0);
    BIGNUM *tmp;
    int ret = -1;
    int check_result;
    if (BN_num_bits(dh->p) > 10000) {
        ERR_put_error(5,(102),(103),"crypto\\dh\\dh_key.c",170);
        goto err;
    }
    ctx = BN_CTX_new();
    if (ctx == ((void *)0))
        goto err;
    BN_CTX_start(ctx);
    tmp = BN_CTX_get(ctx);
    if (tmp == ((void *)0))
        goto err;
    if (dh->priv_key == ((void *)0)) {
        ERR_put_error(5,(102),(100),"crypto\\dh\\dh_key.c",183);
        goto err;
    }
    if (dh->flags & 0x01) {
        mont = BN_MONT_CTX_set_locked(&dh->method_mont_p,
                                      dh->lock, dh->p, ctx);
        BN_set_flags(dh->priv_key, 0x04);
        if (!mont)
            goto err;
    }
    if (!DH_check_pub_key(dh, pub_key, &check_result) || check_result) {
        ERR_put_error(5,(102),(102),"crypto\\dh\\dh_key.c",196);
        goto err;
    }
    if (!dh->
        meth->bn_mod_exp(dh, tmp, pub_key, dh->priv_key, dh->p, ctx, mont)) {
        ERR_put_error(5,(102),(3),"crypto\\dh\\dh_key.c",202);
        goto err;
    }
    ret = BN_bn2bin(tmp, key);
 err:
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    return ret;
}
