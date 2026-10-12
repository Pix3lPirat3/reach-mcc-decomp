typedef unsigned __int64 size_t;
typedef int                int32_t;
typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;
typedef struct bn_mont_ctx_st BN_MONT_CTX;
typedef struct ec_key_st EC_KEY;
typedef struct ec_key_method_st EC_KEY_METHOD;
typedef struct engine_st ENGINE;
typedef struct crypto_ex_data_st CRYPTO_EX_DATA;
typedef void CRYPTO_RWLOCK;
struct crypto_ex_data_st {
    struct stack_st_void *sk;
};
struct stack_st_void;
typedef enum {
    POINT_CONVERSION_COMPRESSED = 2,
    POINT_CONVERSION_UNCOMPRESSED = 4,
    POINT_CONVERSION_HYBRID = 6
} point_conversion_form_t;
typedef struct ec_method_st EC_METHOD;
typedef struct ec_group_st EC_GROUP;
typedef struct ec_point_st EC_POINT;
EC_POINT *EC_POINT_new(const EC_GROUP *group);
int EC_POINT_oct2point(const EC_GROUP *group, EC_POINT *p,
                       const unsigned char *buf, size_t len, BN_CTX *ctx);
int EC_KEY_oct2key(EC_KEY *key, const unsigned char *buf, size_t len,
                   BN_CTX *ctx);
typedef struct ECDSA_SIG_st ECDSA_SIG;
typedef volatile int CRYPTO_REF_COUNT;
struct ec_method_st {
    int flags;
    int field_type;
    int (*group_init) (EC_GROUP *);
    void (*group_finish) (EC_GROUP *);
    void (*group_clear_finish) (EC_GROUP *);
    int (*group_copy) (EC_GROUP *, const EC_GROUP *);
    int (*group_set_curve) (EC_GROUP *, const BIGNUM *p, const BIGNUM *a,
                            const BIGNUM *b, BN_CTX *);
    int (*group_get_curve) (const EC_GROUP *, BIGNUM *p, BIGNUM *a, BIGNUM *b,
                            BN_CTX *);
    int (*group_get_degree) (const EC_GROUP *);
    int (*group_order_bits) (const EC_GROUP *);
    int (*group_check_discriminant) (const EC_GROUP *, BN_CTX *);
    int (*point_init) (EC_POINT *);
    void (*point_finish) (EC_POINT *);
    void (*point_clear_finish) (EC_POINT *);
    int (*point_copy) (EC_POINT *, const EC_POINT *);
    int (*point_set_to_infinity) (const EC_GROUP *, EC_POINT *);
    int (*point_set_Jprojective_coordinates_GFp) (const EC_GROUP *,
                                                  EC_POINT *, const BIGNUM *x,
                                                  const BIGNUM *y,
                                                  const BIGNUM *z, BN_CTX *);
    int (*point_get_Jprojective_coordinates_GFp) (const EC_GROUP *,
                                                  const EC_POINT *, BIGNUM *x,
                                                  BIGNUM *y, BIGNUM *z,
                                                  BN_CTX *);
    int (*point_set_affine_coordinates) (const EC_GROUP *, EC_POINT *,
                                         const BIGNUM *x, const BIGNUM *y,
                                         BN_CTX *);
    int (*point_get_affine_coordinates) (const EC_GROUP *, const EC_POINT *,
                                         BIGNUM *x, BIGNUM *y, BN_CTX *);
    int (*point_set_compressed_coordinates) (const EC_GROUP *, EC_POINT *,
                                             const BIGNUM *x, int y_bit,
                                             BN_CTX *);
    size_t (*point2oct) (const EC_GROUP *, const EC_POINT *,
                         point_conversion_form_t form, unsigned char *buf,
                         size_t len, BN_CTX *);
    int (*oct2point) (const EC_GROUP *, EC_POINT *, const unsigned char *buf,
                      size_t len, BN_CTX *);
    int (*add) (const EC_GROUP *, EC_POINT *r, const EC_POINT *a,
                const EC_POINT *b, BN_CTX *);
    int (*dbl) (const EC_GROUP *, EC_POINT *r, const EC_POINT *a, BN_CTX *);
    int (*invert) (const EC_GROUP *, EC_POINT *, BN_CTX *);
    int (*is_at_infinity) (const EC_GROUP *, const EC_POINT *);
    int (*is_on_curve) (const EC_GROUP *, const EC_POINT *, BN_CTX *);
    int (*point_cmp) (const EC_GROUP *, const EC_POINT *a, const EC_POINT *b,
                      BN_CTX *);
    int (*make_affine) (const EC_GROUP *, EC_POINT *, BN_CTX *);
    int (*points_make_affine) (const EC_GROUP *, size_t num, EC_POINT *[],
                               BN_CTX *);
    int (*mul) (const EC_GROUP *group, EC_POINT *r, const BIGNUM *scalar,
                size_t num, const EC_POINT *points[], const BIGNUM *scalars[],
                BN_CTX *);
    int (*precompute_mult) (EC_GROUP *group, BN_CTX *);
    int (*have_precompute_mult) (const EC_GROUP *group);
    int (*field_mul) (const EC_GROUP *, BIGNUM *r, const BIGNUM *a,
                      const BIGNUM *b, BN_CTX *);
    int (*field_sqr) (const EC_GROUP *, BIGNUM *r, const BIGNUM *a, BN_CTX *);
    int (*field_div) (const EC_GROUP *, BIGNUM *r, const BIGNUM *a,
                      const BIGNUM *b, BN_CTX *);
    int (*field_inv) (const EC_GROUP *, BIGNUM *r, const BIGNUM *a, BN_CTX *);
    int (*field_encode) (const EC_GROUP *, BIGNUM *r, const BIGNUM *a,
                         BN_CTX *);
    int (*field_decode) (const EC_GROUP *, BIGNUM *r, const BIGNUM *a,
                         BN_CTX *);
    int (*field_set_to_one) (const EC_GROUP *, BIGNUM *r, BN_CTX *);
    size_t (*priv2oct)(const EC_KEY *eckey, unsigned char *buf, size_t len);
    int (*oct2priv)(EC_KEY *eckey, const unsigned char *buf, size_t len);
    int (*set_private)(EC_KEY *eckey, const BIGNUM *priv_key);
    int (*keygen)(EC_KEY *eckey);
    int (*keycheck)(const EC_KEY *eckey);
    int (*keygenpub)(EC_KEY *eckey);
    int (*keycopy)(EC_KEY *dst, const EC_KEY *src);
    void (*keyfinish)(EC_KEY *eckey);
    int (*ecdh_compute_key)(unsigned char **pout, size_t *poutlen,
                            const EC_POINT *pub_key, const EC_KEY *ecdh);
    int (*field_inverse_mod_ord)(const EC_GROUP *, BIGNUM *r,
                                 const BIGNUM *x, BN_CTX *);
    int (*blind_coordinates)(const EC_GROUP *group, EC_POINT *p, BN_CTX *ctx);
    int (*ladder_pre)(const EC_GROUP *group,
                      EC_POINT *r, EC_POINT *s,
                      EC_POINT *p, BN_CTX *ctx);
    int (*ladder_step)(const EC_GROUP *group,
                       EC_POINT *r, EC_POINT *s,
                       EC_POINT *p, BN_CTX *ctx);
    int (*ladder_post)(const EC_GROUP *group,
                       EC_POINT *r, EC_POINT *s,
                       EC_POINT *p, BN_CTX *ctx);
};
typedef struct nistp224_pre_comp_st NISTP224_PRE_COMP;
typedef struct nistp256_pre_comp_st NISTP256_PRE_COMP;
typedef struct nistp521_pre_comp_st NISTP521_PRE_COMP;
typedef struct nistz256_pre_comp_st NISTZ256_PRE_COMP;
typedef struct ec_pre_comp_st EC_PRE_COMP;
struct ec_group_st {
    const EC_METHOD *meth;
    EC_POINT *generator;
    BIGNUM *order, *cofactor;
    int curve_name;
    int asn1_flag;
    point_conversion_form_t asn1_form;
    unsigned char *seed;
    size_t seed_len;
    BIGNUM *field;
    int poly[6];
    BIGNUM *a, *b;
    int a_is_minus3;
    void *field_data1;
    void *field_data2;
    int (*field_mod_func) (BIGNUM *, const BIGNUM *, const BIGNUM *,
                           BN_CTX *);
    BN_MONT_CTX *mont_data;
    enum {
        PCT_none,
        PCT_nistp224, PCT_nistp256, PCT_nistp521, PCT_nistz256,
        PCT_ec
    } pre_comp_type;
    union {
        NISTP224_PRE_COMP *nistp224;
        NISTP256_PRE_COMP *nistp256;
        NISTP521_PRE_COMP *nistp521;
        NISTZ256_PRE_COMP *nistz256;
        EC_PRE_COMP *ec;
    } pre_comp;
};
struct ec_key_st {
    const EC_KEY_METHOD *meth;
    ENGINE *engine;
    int version;
    EC_GROUP *group;
    EC_POINT *pub_key;
    BIGNUM *priv_key;
    unsigned int enc_flag;
    point_conversion_form_t conv_form;
    CRYPTO_REF_COUNT references;
    int flags;
    CRYPTO_EX_DATA ex_data;
    CRYPTO_RWLOCK *lock;
};
struct ec_point_st {
    const EC_METHOD *meth;
    int curve_name;
    BIGNUM *X;
    BIGNUM *Y;
    BIGNUM *Z;
    int Z_is_one;
};
struct ec_key_method_st {
    const char *name;
    int32_t flags;
    int (*init)(EC_KEY *key);
    void (*finish)(EC_KEY *key);
    int (*copy)(EC_KEY *dest, const EC_KEY *src);
    int (*set_group)(EC_KEY *key, const EC_GROUP *grp);
    int (*set_private)(EC_KEY *key, const BIGNUM *priv_key);
    int (*set_public)(EC_KEY *key, const EC_POINT *pub_key);
    int (*keygen)(EC_KEY *key);
    int (*compute_key)(unsigned char **pout, size_t *poutlen,
                       const EC_POINT *pub_key, const EC_KEY *ecdh);
    int (*sign)(int type, const unsigned char *dgst, int dlen, unsigned char
                *sig, unsigned int *siglen, const BIGNUM *kinv,
                const BIGNUM *r, EC_KEY *eckey);
    int (*sign_setup)(EC_KEY *eckey, BN_CTX *ctx_in, BIGNUM **kinvp,
                      BIGNUM **rp);
    ECDSA_SIG *(*sign_sig)(const unsigned char *dgst, int dgst_len,
                           const BIGNUM *in_kinv, const BIGNUM *in_r,
                           EC_KEY *eckey);
    int (*verify)(int type, const unsigned char *dgst, int dgst_len,
                  const unsigned char *sigbuf, int sig_len, EC_KEY *eckey);
    int (*verify_sig)(const unsigned char *dgst, int dgst_len,
                      const ECDSA_SIG *sig, EC_KEY *eckey);
};
struct ECDSA_SIG_st {
    BIGNUM *r;
    BIGNUM *s;
};
struct ec_key_st;
int EC_KEY_oct2key(EC_KEY *key, const unsigned char *buf, size_t len,
                   BN_CTX *ctx)
{
    if (key == ((void *)0) || key->group == ((void *)0))
        return 0;
    if (key->pub_key == ((void *)0))
        key->pub_key = EC_POINT_new(key->group);
    if (key->pub_key == ((void *)0))
        return 0;
    if (EC_POINT_oct2point(key->group, key->pub_key, buf, len, ctx) == 0)
        return 0;
    if ((key->group->meth->flags & 0x2) == 0)
        key->conv_form = (point_conversion_form_t)(buf[0] & ~0x01);
    return 1;
}
