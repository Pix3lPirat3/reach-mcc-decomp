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
typedef volatile int CRYPTO_REF_COUNT;
int BN_num_bits(const BIGNUM *a);
int DH_size(const DH *dh);
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
struct dh_st;
int DH_size(const DH *dh)
{
    return ((BN_num_bits(dh->p)+7)/8);
}
