typedef int                int32_t;
typedef struct asn1_string_st ASN1_INTEGER;
typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;
typedef struct bn_blinding_st BN_BLINDING;
typedef struct bn_mont_ctx_st BN_MONT_CTX;
typedef struct bn_gencb_st BN_GENCB;
typedef struct rsa_st RSA;
typedef struct rsa_meth_st RSA_METHOD;
typedef struct X509_algor_st X509_ALGOR;
typedef struct engine_st ENGINE;
typedef struct crypto_ex_data_st CRYPTO_EX_DATA;
typedef void CRYPTO_RWLOCK;
struct crypto_ex_data_st {
    struct stack_st_void *sk;
};
struct stack_st_void;
struct X509_algor_st;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
int RSA_private_decrypt(int flen, const unsigned char *from,
                        unsigned char *to, RSA *rsa, int padding);
typedef struct rsa_pss_params_st {
    X509_ALGOR *hashAlgorithm;
    X509_ALGOR *maskGenAlgorithm;
    ASN1_INTEGER *saltLength;
    ASN1_INTEGER *trailerField;
    X509_ALGOR *maskHash;
} RSA_PSS_PARAMS;
typedef volatile int CRYPTO_REF_COUNT;
struct stack_st_RSA_PRIME_INFO;
struct rsa_st {
    int pad;
    int32_t version;
    const RSA_METHOD *meth;
    ENGINE *engine;
    BIGNUM *n;
    BIGNUM *e;
    BIGNUM *d;
    BIGNUM *p;
    BIGNUM *q;
    BIGNUM *dmp1;
    BIGNUM *dmq1;
    BIGNUM *iqmp;
    struct stack_st_RSA_PRIME_INFO *prime_infos;
    RSA_PSS_PARAMS *pss;
    CRYPTO_EX_DATA ex_data;
    CRYPTO_REF_COUNT references;
    int flags;
    BN_MONT_CTX *_method_mod_n;
    BN_MONT_CTX *_method_mod_p;
    BN_MONT_CTX *_method_mod_q;
    char *bignum_data;
    BN_BLINDING *blinding;
    BN_BLINDING *mt_blinding;
    CRYPTO_RWLOCK *lock;
};
struct rsa_meth_st {
    char *name;
    int (*rsa_pub_enc) (int flen, const unsigned char *from,
                        unsigned char *to, RSA *rsa, int padding);
    int (*rsa_pub_dec) (int flen, const unsigned char *from,
                        unsigned char *to, RSA *rsa, int padding);
    int (*rsa_priv_enc) (int flen, const unsigned char *from,
                         unsigned char *to, RSA *rsa, int padding);
    int (*rsa_priv_dec) (int flen, const unsigned char *from,
                         unsigned char *to, RSA *rsa, int padding);
    int (*rsa_mod_exp) (BIGNUM *r0, const BIGNUM *I, RSA *rsa, BN_CTX *ctx);
    int (*bn_mod_exp) (BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                       const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);
    int (*init) (RSA *rsa);
    int (*finish) (RSA *rsa);
    int flags;
    char *app_data;
    int (*rsa_sign) (int type,
                     const unsigned char *m, unsigned int m_length,
                     unsigned char *sigret, unsigned int *siglen,
                     const RSA *rsa);
    int (*rsa_verify) (int dtype, const unsigned char *m,
                       unsigned int m_length, const unsigned char *sigbuf,
                       unsigned int siglen, const RSA *rsa);
    int (*rsa_keygen) (RSA *rsa, int bits, BIGNUM *e, BN_GENCB *cb);
    int (*rsa_multi_prime_keygen) (RSA *rsa, int bits, int primes,
                                   BIGNUM *e, BN_GENCB *cb);
};
int RSA_private_decrypt(int flen, const unsigned char *from,
                        unsigned char *to, RSA *rsa, int padding)
{
    return rsa->meth->rsa_priv_dec(flen, from, to, rsa, padding);
}
