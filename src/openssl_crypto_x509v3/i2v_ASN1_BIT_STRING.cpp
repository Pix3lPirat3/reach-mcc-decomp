typedef struct asn1_string_st ASN1_BIT_STRING;
typedef struct ASN1_ITEM_st ASN1_ITEM;
typedef struct bio_st BIO;
typedef struct x509_st X509;
typedef struct X509_crl_st X509_CRL;
struct stack_st_CONF_VALUE;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
typedef const ASN1_ITEM *ASN1_ITEM_EXP (void);
typedef struct BIT_STRING_BITNAME_st {
    int bitnum;
    const char *lname;
    const char *sname;
} BIT_STRING_BITNAME;
int ASN1_BIT_STRING_get_bit(const ASN1_BIT_STRING *a, int n);
typedef struct X509_req_st X509_REQ;
struct v3_ext_method;
struct v3_ext_ctx;
typedef void *(*X509V3_EXT_NEW)(void);
typedef void (*X509V3_EXT_FREE) (void *);
typedef void *(*X509V3_EXT_D2I)(void *, const unsigned char **, long);
typedef int (*X509V3_EXT_I2D) (void *, unsigned char **);
typedef struct stack_st_CONF_VALUE *
    (*X509V3_EXT_I2V) (const struct v3_ext_method *method, void *ext,
                       struct stack_st_CONF_VALUE *extlist);
typedef void *(*X509V3_EXT_V2I)(const struct v3_ext_method *method,
                                struct v3_ext_ctx *ctx,
                                struct stack_st_CONF_VALUE *values);
typedef char *(*X509V3_EXT_I2S)(const struct v3_ext_method *method,
                                void *ext);
typedef void *(*X509V3_EXT_S2I)(const struct v3_ext_method *method,
                                struct v3_ext_ctx *ctx, const char *str);
typedef int (*X509V3_EXT_I2R) (const struct v3_ext_method *method, void *ext,
                               BIO *out, int indent);
typedef void *(*X509V3_EXT_R2I)(const struct v3_ext_method *method,
                                struct v3_ext_ctx *ctx, const char *str);
struct v3_ext_method {
    int ext_nid;
    int ext_flags;
    ASN1_ITEM_EXP *it;
    X509V3_EXT_NEW ext_new;
    X509V3_EXT_FREE ext_free;
    X509V3_EXT_D2I d2i;
    X509V3_EXT_I2D i2d;
    X509V3_EXT_I2S i2s;
    X509V3_EXT_S2I s2i;
    X509V3_EXT_I2V i2v;
    X509V3_EXT_V2I v2i;
    X509V3_EXT_I2R i2r;
    X509V3_EXT_R2I r2i;
    void *usr_data;
};
typedef struct X509V3_CONF_METHOD_st {
    char *(*get_string) (void *db, const char *section, const char *value);
    struct stack_st_CONF_VALUE *(*get_section) (void *db, const char *section);
    void (*free_string) (void *db, char *string);
    void (*free_section) (void *db, struct stack_st_CONF_VALUE *section);
} X509V3_CONF_METHOD;
struct v3_ext_ctx {
    int flags;
    X509 *issuer_cert;
    X509 *subject_cert;
    X509_REQ *subject_req;
    X509_CRL *crl;
    X509V3_CONF_METHOD *db_meth;
    void *db;
};
typedef struct v3_ext_method X509V3_EXT_METHOD;
struct stack_st_CONF_VALUE *i2v_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,
                                          ASN1_BIT_STRING *bits,
                                          struct stack_st_CONF_VALUE *extlist);
int X509V3_add_value(const char *name, const char *value,
                     struct stack_st_CONF_VALUE **extlist);
struct stack_st_CONF_VALUE *i2v_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,
                                          ASN1_BIT_STRING *bits,
                                          struct stack_st_CONF_VALUE *ret)
{
    BIT_STRING_BITNAME *bnam;
    for (bnam = method->usr_data; bnam->lname; bnam++) {
        if (ASN1_BIT_STRING_get_bit(bits, bnam->bitnum))
            X509V3_add_value(bnam->lname, ((void *)0), &ret);
    }
    return ret;
}
