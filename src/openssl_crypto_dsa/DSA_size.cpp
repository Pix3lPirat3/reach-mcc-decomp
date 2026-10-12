typedef int                int32_t;
typedef struct asn1_string_st ASN1_INTEGER;
typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;
typedef struct bn_mont_ctx_st BN_MONT_CTX;
typedef struct bn_gencb_st BN_GENCB;
typedef struct dsa_st DSA;
typedef struct dsa_method DSA_METHOD;
typedef struct engine_st ENGINE;
typedef struct crypto_ex_data_st CRYPTO_EX_DATA;
typedef void CRYPTO_RWLOCK;
struct crypto_ex_data_st {
    struct stack_st_void *sk;
};
struct stack_st_void;
typedef volatile int CRYPTO_REF_COUNT;
int BN_num_bits(const BIGNUM *a);
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
int i2d_ASN1_INTEGER(ASN1_INTEGER *a, unsigned char **out);
int ASN1_object_size(int constructed, int length, int tag);
typedef struct DSA_SIG_st DSA_SIG;
int DSA_size(const DSA *);
struct dsa_st {
    int pad;
    int32_t version;
    BIGNUM *p;
    BIGNUM *q;
    BIGNUM *g;
    BIGNUM *pub_key;
    BIGNUM *priv_key;
    int flags;
    BN_MONT_CTX *method_mont_p;
    CRYPTO_REF_COUNT references;
    CRYPTO_EX_DATA ex_data;
    const DSA_METHOD *meth;
    ENGINE *engine;
    CRYPTO_RWLOCK *lock;
};
struct DSA_SIG_st {
    BIGNUM *r;
    BIGNUM *s;
};
struct dsa_method {
    char *name;
    DSA_SIG *(*dsa_do_sign) (const unsigned char *dgst, int dlen, DSA *dsa);
    int (*dsa_sign_setup) (DSA *dsa, BN_CTX *ctx_in, BIGNUM **kinvp,
                           BIGNUM **rp);
    int (*dsa_do_verify) (const unsigned char *dgst, int dgst_len,
                          DSA_SIG *sig, DSA *dsa);
    int (*dsa_mod_exp) (DSA *dsa, BIGNUM *rr, const BIGNUM *a1,
                        const BIGNUM *p1, const BIGNUM *a2, const BIGNUM *p2,
                        const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont);
    int (*bn_mod_exp) (DSA *dsa, BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                       const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);
    int (*init) (DSA *dsa);
    int (*finish) (DSA *dsa);
    int flags;
    void *app_data;
    int (*dsa_paramgen) (DSA *dsa, int bits,
                         const unsigned char *seed, int seed_len,
                         int *counter_ret, unsigned long *h_ret,
                         BN_GENCB *cb);
    int (*dsa_keygen) (DSA *dsa);
};
struct dsa_st;
int DSA_size(const DSA *r)
{
    int ret, i;
    ASN1_INTEGER bs;
    unsigned char buf[4];
    i = BN_num_bits(r->q);
    bs.length = (i + 7) / 8;
    bs.data = buf;
    bs.type = 2;
    buf[0] = 0xff;
    i = i2d_ASN1_INTEGER(&bs, ((void *)0));
    i += i;
    ret = ASN1_object_size(1, i, 16);
    return ret;
}
