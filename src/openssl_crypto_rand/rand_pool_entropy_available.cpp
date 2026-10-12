typedef unsigned __int64 size_t;
typedef __int64                       __time64_t;
typedef __time64_t time_t;
typedef struct evp_cipher_st EVP_CIPHER;
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;
typedef struct rand_drbg_st RAND_DRBG;
typedef struct crypto_ex_data_st CRYPTO_EX_DATA;
typedef void CRYPTO_RWLOCK;
struct crypto_ex_data_st {
    struct stack_st_void *sk;
};
struct stack_st_void;
typedef struct rand_pool_st RAND_POOL;
size_t rand_pool_entropy_available(RAND_POOL *pool);
typedef size_t (*RAND_DRBG_get_entropy_fn)(RAND_DRBG *drbg,
                                           unsigned char **pout,
                                           int entropy, size_t min_len,
                                           size_t max_len,
                                           int prediction_resistance);
typedef void (*RAND_DRBG_cleanup_entropy_fn)(RAND_DRBG *ctx,
                                             unsigned char *out, size_t outlen);
typedef size_t (*RAND_DRBG_get_nonce_fn)(RAND_DRBG *drbg, unsigned char **pout,
                                         int entropy, size_t min_len,
                                         size_t max_len);
typedef void (*RAND_DRBG_cleanup_nonce_fn)(RAND_DRBG *drbg,
                                           unsigned char *out, size_t outlen);
typedef enum drbg_status_e {
    DRBG_UNINITIALISED,
    DRBG_READY,
    DRBG_ERROR
} DRBG_STATUS;
typedef int (*RAND_DRBG_instantiate_fn)(RAND_DRBG *ctx,
                                        const unsigned char *ent,
                                        size_t entlen,
                                        const unsigned char *nonce,
                                        size_t noncelen,
                                        const unsigned char *pers,
                                        size_t perslen);
typedef int (*RAND_DRBG_reseed_fn)(RAND_DRBG *ctx,
                                   const unsigned char *ent,
                                   size_t entlen,
                                   const unsigned char *adin,
                                   size_t adinlen);
typedef int (*RAND_DRBG_generate_fn)(RAND_DRBG *ctx,
                                     unsigned char *out,
                                     size_t outlen,
                                     const unsigned char *adin,
                                     size_t adinlen);
typedef int (*RAND_DRBG_uninstantiate_fn)(RAND_DRBG *ctx);
typedef struct rand_drbg_method_st {
    RAND_DRBG_instantiate_fn instantiate;
    RAND_DRBG_reseed_fn reseed;
    RAND_DRBG_generate_fn generate;
    RAND_DRBG_uninstantiate_fn uninstantiate;
} RAND_DRBG_METHOD;
typedef struct rand_drbg_ctr_st {
    EVP_CIPHER_CTX *ctx;
    EVP_CIPHER_CTX *ctx_df;
    const EVP_CIPHER *cipher;
    size_t keylen;
    unsigned char K[32];
    unsigned char V[16];
    unsigned char bltmp[16];
    size_t bltmp_pos;
    unsigned char KX[48];
} RAND_DRBG_CTR;
struct rand_pool_st {
    unsigned char *buffer;
    size_t len;
    int attached;
    size_t min_len;
    size_t max_len;
    size_t entropy;
    size_t entropy_requested;
};
struct rand_drbg_st {
    CRYPTO_RWLOCK *lock;
    RAND_DRBG *parent;
    int secure;
    int type;
    int fork_count;
    unsigned short flags;
    struct rand_pool_st *seed_pool;
    struct rand_pool_st *adin_pool;
    int strength;
    size_t max_request;
    size_t min_entropylen, max_entropylen;
    size_t min_noncelen, max_noncelen;
    size_t max_perslen, max_adinlen;
    unsigned int reseed_gen_counter;
    unsigned int reseed_interval;
    time_t reseed_time;
    time_t reseed_time_interval;
    volatile unsigned int reseed_prop_counter;
    unsigned int reseed_next_counter;
    size_t seedlen;
    DRBG_STATUS state;
    CRYPTO_EX_DATA ex_data;
    union {
        RAND_DRBG_CTR ctr;
    } data;
    RAND_DRBG_METHOD *meth;
    RAND_DRBG_get_entropy_fn get_entropy;
    RAND_DRBG_cleanup_entropy_fn cleanup_entropy;
    RAND_DRBG_get_nonce_fn get_nonce;
    RAND_DRBG_cleanup_nonce_fn cleanup_nonce;
};
size_t rand_pool_entropy_available(RAND_POOL *pool)
{
    if (pool->entropy < pool->entropy_requested)
        return 0;
    if (pool->len < pool->min_len)
        return 0;
    return pool->entropy;
}
