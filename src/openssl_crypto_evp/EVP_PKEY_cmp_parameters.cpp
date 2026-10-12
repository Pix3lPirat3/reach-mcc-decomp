typedef unsigned __int64 size_t;
typedef struct asn1_string_st ASN1_INTEGER;
typedef struct asn1_string_st ASN1_ENUMERATED;
typedef struct asn1_string_st ASN1_BIT_STRING;
typedef struct asn1_string_st ASN1_OCTET_STRING;
typedef struct asn1_string_st ASN1_PRINTABLESTRING;
typedef struct asn1_string_st ASN1_T61STRING;
typedef struct asn1_string_st ASN1_IA5STRING;
typedef struct asn1_string_st ASN1_GENERALSTRING;
typedef struct asn1_string_st ASN1_UNIVERSALSTRING;
typedef struct asn1_string_st ASN1_BMPSTRING;
typedef struct asn1_string_st ASN1_UTCTIME;
typedef struct asn1_string_st ASN1_GENERALIZEDTIME;
typedef struct asn1_string_st ASN1_VISIBLESTRING;
typedef struct asn1_string_st ASN1_UTF8STRING;
typedef struct asn1_string_st ASN1_STRING;
typedef int ASN1_BOOLEAN;
typedef struct asn1_object_st ASN1_OBJECT;
typedef struct ASN1_ITEM_st ASN1_ITEM;
typedef struct asn1_pctx_st ASN1_PCTX;
typedef struct bio_st BIO;
typedef struct evp_md_ctx_st EVP_MD_CTX;
typedef struct evp_pkey_st EVP_PKEY;
typedef struct evp_pkey_asn1_method_st EVP_PKEY_ASN1_METHOD;
typedef struct X509_algor_st X509_ALGOR;
typedef struct X509_pubkey_st X509_PUBKEY;
typedef struct x509_sig_info_st X509_SIG_INFO;
typedef struct pkcs8_priv_key_info_st PKCS8_PRIV_KEY_INFO;
typedef struct engine_st ENGINE;
typedef void CRYPTO_RWLOCK;
typedef volatile int CRYPTO_REF_COUNT;
struct X509_algor_st;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
typedef struct ASN1_VALUE_st ASN1_VALUE;
typedef struct asn1_type_st {
    int type;
    union {
        char *ptr;
        ASN1_BOOLEAN boolean;
        ASN1_STRING *asn1_string;
        ASN1_OBJECT *object;
        ASN1_INTEGER *integer;
        ASN1_ENUMERATED *enumerated;
        ASN1_BIT_STRING *bit_string;
        ASN1_OCTET_STRING *octet_string;
        ASN1_PRINTABLESTRING *printablestring;
        ASN1_T61STRING *t61string;
        ASN1_IA5STRING *ia5string;
        ASN1_GENERALSTRING *generalstring;
        ASN1_BMPSTRING *bmpstring;
        ASN1_UNIVERSALSTRING *universalstring;
        ASN1_UTCTIME *utctime;
        ASN1_GENERALIZEDTIME *generalizedtime;
        ASN1_VISIBLESTRING *visiblestring;
        ASN1_UTF8STRING *utf8string;
        ASN1_STRING *set;
        ASN1_STRING *sequence;
        ASN1_VALUE *asn1_value;
    } value;
} ASN1_TYPE;
struct rsa_st;
struct dsa_st;
struct dh_st;
struct ec_key_st;
int EVP_PKEY_cmp_parameters(const EVP_PKEY *a, const EVP_PKEY *b);
struct X509_algor_st {
    ASN1_OBJECT *algorithm;
    ASN1_TYPE *parameter;
}  ;
struct stack_st_X509_ATTRIBUTE;
struct evp_pkey_asn1_method_st {
    int pkey_id;
    int pkey_base_id;
    unsigned long pkey_flags;
    char *pem_str;
    char *info;
    int (*pub_decode) (EVP_PKEY *pk, X509_PUBKEY *pub);
    int (*pub_encode) (X509_PUBKEY *pub, const EVP_PKEY *pk);
    int (*pub_cmp) (const EVP_PKEY *a, const EVP_PKEY *b);
    int (*pub_print) (BIO *out, const EVP_PKEY *pkey, int indent,
                      ASN1_PCTX *pctx);
    int (*priv_decode) (EVP_PKEY *pk, const PKCS8_PRIV_KEY_INFO *p8inf);
    int (*priv_encode) (PKCS8_PRIV_KEY_INFO *p8, const EVP_PKEY *pk);
    int (*priv_print) (BIO *out, const EVP_PKEY *pkey, int indent,
                       ASN1_PCTX *pctx);
    int (*pkey_size) (const EVP_PKEY *pk);
    int (*pkey_bits) (const EVP_PKEY *pk);
    int (*pkey_security_bits) (const EVP_PKEY *pk);
    int (*param_decode) (EVP_PKEY *pkey,
                         const unsigned char **pder, int derlen);
    int (*param_encode) (const EVP_PKEY *pkey, unsigned char **pder);
    int (*param_missing) (const EVP_PKEY *pk);
    int (*param_copy) (EVP_PKEY *to, const EVP_PKEY *from);
    int (*param_cmp) (const EVP_PKEY *a, const EVP_PKEY *b);
    int (*param_print) (BIO *out, const EVP_PKEY *pkey, int indent,
                        ASN1_PCTX *pctx);
    int (*sig_print) (BIO *out,
                      const X509_ALGOR *sigalg, const ASN1_STRING *sig,
                      int indent, ASN1_PCTX *pctx);
    void (*pkey_free) (EVP_PKEY *pkey);
    int (*pkey_ctrl) (EVP_PKEY *pkey, int op, long arg1, void *arg2);
    int (*old_priv_decode) (EVP_PKEY *pkey,
                            const unsigned char **pder, int derlen);
    int (*old_priv_encode) (const EVP_PKEY *pkey, unsigned char **pder);
    int (*item_verify) (EVP_MD_CTX *ctx, const ASN1_ITEM *it, void *asn,
                        X509_ALGOR *a, ASN1_BIT_STRING *sig, EVP_PKEY *pkey);
    int (*item_sign) (EVP_MD_CTX *ctx, const ASN1_ITEM *it, void *asn,
                      X509_ALGOR *alg1, X509_ALGOR *alg2,
                      ASN1_BIT_STRING *sig);
    int (*siginf_set) (X509_SIG_INFO *siginf, const X509_ALGOR *alg,
                       const ASN1_STRING *sig);
    int (*pkey_check) (const EVP_PKEY *pk);
    int (*pkey_public_check) (const EVP_PKEY *pk);
    int (*pkey_param_check) (const EVP_PKEY *pk);
    int (*set_priv_key) (EVP_PKEY *pk, const unsigned char *priv, size_t len);
    int (*set_pub_key) (EVP_PKEY *pk, const unsigned char *pub, size_t len);
    int (*get_priv_key) (const EVP_PKEY *pk, unsigned char *priv, size_t *len);
    int (*get_pub_key) (const EVP_PKEY *pk, unsigned char *pub, size_t *len);
}  ;
struct asn1_object_st {
    const char *sn, *ln;
    int nid;
    int length;
    const unsigned char *data;
    int flags;
};
struct asn1_pctx_st {
    unsigned long flags;
    unsigned long nm_flags;
    unsigned long cert_flags;
    unsigned long oid_flags;
    unsigned long str_flags;
}  ;
typedef struct {
    unsigned char pubkey[57];
    unsigned char *privkey;
} ECX_KEY;
struct evp_pkey_st {
    int type;
    int save_type;
    CRYPTO_REF_COUNT references;
    const EVP_PKEY_ASN1_METHOD *ameth;
    ENGINE *engine;
    ENGINE *pmeth_engine;
    union {
        void *ptr;
        struct rsa_st *rsa;
        struct dsa_st *dsa;
        struct dh_st *dh;
        struct ec_key_st *ec;
        ECX_KEY *ecx;
    } pkey;
    int save_parameters;
    struct stack_st_X509_ATTRIBUTE *attributes;
    CRYPTO_RWLOCK *lock;
}  ;
int EVP_PKEY_cmp_parameters(const EVP_PKEY *a, const EVP_PKEY *b)
{
    if (a->type != b->type)
        return -1;
    if (a->ameth && a->ameth->param_cmp)
        return a->ameth->param_cmp(a, b);
    return -2;
}
