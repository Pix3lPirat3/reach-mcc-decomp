__pragma(warning(disable: 4100))
typedef unsigned __int64 size_t;
typedef unsigned int       uint32_t;
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
typedef struct asn1_string_st ASN1_TIME;
typedef struct asn1_string_st ASN1_GENERALIZEDTIME;
typedef struct asn1_string_st ASN1_VISIBLESTRING;
typedef struct asn1_string_st ASN1_UTF8STRING;
typedef struct asn1_string_st ASN1_STRING;
typedef int ASN1_BOOLEAN;
typedef int ASN1_NULL;
typedef struct asn1_object_st ASN1_OBJECT;
typedef struct ASN1_ITEM_st ASN1_ITEM;
typedef struct bio_st BIO;
typedef struct buf_mem_st BUF_MEM;
typedef struct x509_st X509;
typedef struct X509_algor_st X509_ALGOR;
typedef struct X509_crl_st X509_CRL;
typedef struct x509_crl_method_st X509_CRL_METHOD;
typedef struct X509_name_st X509_NAME;
typedef struct X509_pubkey_st X509_PUBKEY;
typedef struct x509_sig_info_st X509_SIG_INFO;
typedef struct X509_POLICY_CACHE_st X509_POLICY_CACHE;
typedef struct AUTHORITY_KEYID_st AUTHORITY_KEYID;
typedef struct ISSUING_DIST_POINT_st ISSUING_DIST_POINT;
typedef struct NAME_CONSTRAINTS_st NAME_CONSTRAINTS;
typedef struct crypto_ex_data_st CRYPTO_EX_DATA;
typedef void CRYPTO_RWLOCK;
struct crypto_ex_data_st {
    struct stack_st_void *sk;
};
struct stack_st_void;
char *OPENSSL_buf2hexstr(const unsigned char *buffer, long len);
struct buf_mem_st {
    size_t length;
    char *data;
    size_t max;
    unsigned long flags;
};
struct X509_algor_st;
struct stack_st_X509_ALGOR;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
typedef struct ASN1_ENCODING_st {
    unsigned char *enc;
    long len;
    int modified;
} ASN1_ENCODING;
typedef struct ASN1_VALUE_st ASN1_VALUE;
typedef const ASN1_ITEM *ASN1_ITEM_EXP (void);
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
struct stack_st_ASN1_OBJECT;
struct X509_algor_st {
    ASN1_OBJECT *algorithm;
    ASN1_TYPE *parameter;
}  ;
typedef struct X509_val_st {
    ASN1_TIME *notBefore;
    ASN1_TIME *notAfter;
} X509_VAL;
struct stack_st_X509_NAME_ENTRY;
struct stack_st_X509_EXTENSION;
struct stack_st_X509_ATTRIBUTE;
typedef struct X509_req_info_st X509_REQ_INFO;
typedef struct X509_req_st X509_REQ;
typedef struct x509_cert_aux_st X509_CERT_AUX;
typedef struct x509_cinf_st X509_CINF;
struct stack_st_X509_REVOKED;
typedef struct X509_crl_info_st X509_CRL_INFO;
struct stack_st_CONF_VALUE;
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
struct stack_st_GENERAL_NAME;
typedef struct stack_st_GENERAL_NAME GENERAL_NAMES;
struct stack_st_GENERAL_NAMES;
typedef struct DIST_POINT_NAME_st {
    int type;
    union {
        GENERAL_NAMES *fullname;
        struct stack_st_X509_NAME_ENTRY *relativename;
    } name;
    X509_NAME *dpname;
} DIST_POINT_NAME;
struct stack_st_DIST_POINT;
struct AUTHORITY_KEYID_st {
    ASN1_OCTET_STRING *keyid;
    GENERAL_NAMES *issuer;
    ASN1_INTEGER *serial;
};
struct stack_st_GENERAL_SUBTREE;
struct NAME_CONSTRAINTS_st {
    struct stack_st_GENERAL_SUBTREE *permittedSubtrees;
    struct stack_st_GENERAL_SUBTREE *excludedSubtrees;
};
struct ISSUING_DIST_POINT_st {
    DIST_POINT_NAME *distpoint;
    int onlyuser;
    int onlyCA;
    ASN1_BIT_STRING *onlysomereasons;
    int indirectCRL;
    int onlyattr;
};
char *i2s_ASN1_OCTET_STRING(X509V3_EXT_METHOD *method,
                            const ASN1_OCTET_STRING *ia5);
typedef struct stack_st_ASIdOrRange ASIdOrRanges;
struct stack_st_ASIdOrRange;
typedef struct ASIdentifierChoice_st {
    int type;
    union {
        ASN1_NULL *inherit;
        ASIdOrRanges *asIdsOrRanges;
    } u;
} ASIdentifierChoice;
typedef struct ASIdentifiers_st {
    ASIdentifierChoice *asnum, *rdi;
} ASIdentifiers;
struct stack_st_IPAddressFamily;
typedef volatile int CRYPTO_REF_COUNT;
struct X509_name_st {
    struct stack_st_X509_NAME_ENTRY *entries;
    int modified;
    BUF_MEM *bytes;
    unsigned char *canon_enc;
    int canon_enclen;
}  ;
struct x509_sig_info_st {
    int mdnid;
    int pknid;
    int secbits;
    uint32_t flags;
};
struct X509_req_info_st {
    ASN1_ENCODING enc;
    ASN1_INTEGER *version;
    X509_NAME *subject;
    X509_PUBKEY *pubkey;
    struct stack_st_X509_ATTRIBUTE *attributes;
};
struct X509_req_st {
    X509_REQ_INFO req_info;
    X509_ALGOR sig_alg;
    ASN1_BIT_STRING *signature;
    CRYPTO_REF_COUNT references;
    CRYPTO_RWLOCK *lock;
};
struct X509_crl_info_st {
    ASN1_INTEGER *version;
    X509_ALGOR sig_alg;
    X509_NAME *issuer;
    ASN1_TIME *lastUpdate;
    ASN1_TIME *nextUpdate;
    struct stack_st_X509_REVOKED *revoked;
    struct stack_st_X509_EXTENSION *extensions;
    ASN1_ENCODING enc;
};
struct X509_crl_st {
    X509_CRL_INFO crl;
    X509_ALGOR sig_alg;
    ASN1_BIT_STRING signature;
    CRYPTO_REF_COUNT references;
    int flags;
    AUTHORITY_KEYID *akid;
    ISSUING_DIST_POINT *idp;
    int idp_flags;
    int idp_reasons;
    ASN1_INTEGER *crl_number;
    ASN1_INTEGER *base_crl_number;
    struct stack_st_GENERAL_NAMES *issuers;
    unsigned char sha1_hash[20];
    const X509_CRL_METHOD *meth;
    void *meth_data;
    CRYPTO_RWLOCK *lock;
};
struct x509_cert_aux_st {
    struct stack_st_ASN1_OBJECT *trust;
    struct stack_st_ASN1_OBJECT *reject;
    ASN1_UTF8STRING *alias;
    ASN1_OCTET_STRING *keyid;
    struct stack_st_X509_ALGOR *other;
};
struct x509_cinf_st {
    ASN1_INTEGER *version;
    ASN1_INTEGER serialNumber;
    X509_ALGOR signature;
    X509_NAME *issuer;
    X509_VAL validity;
    X509_NAME *subject;
    X509_PUBKEY *key;
    ASN1_BIT_STRING *issuerUID;
    ASN1_BIT_STRING *subjectUID;
    struct stack_st_X509_EXTENSION *extensions;
    ASN1_ENCODING enc;
};
struct x509_st {
    X509_CINF cert_info;
    X509_ALGOR sig_alg;
    ASN1_BIT_STRING signature;
    X509_SIG_INFO siginf;
    CRYPTO_REF_COUNT references;
    CRYPTO_EX_DATA ex_data;
    long ex_pathlen;
    long ex_pcpathlen;
    uint32_t ex_flags;
    uint32_t ex_kusage;
    uint32_t ex_xkusage;
    uint32_t ex_nscert;
    ASN1_OCTET_STRING *skid;
    AUTHORITY_KEYID *akid;
    X509_POLICY_CACHE *policy_cache;
    struct stack_st_DIST_POINT *crldp;
    struct stack_st_GENERAL_NAME *altname;
    NAME_CONSTRAINTS *nc;
    struct stack_st_IPAddressFamily *rfc3779_addr;
    struct ASIdentifiers_st *rfc3779_asid;
    unsigned char sha1_hash[20];
    X509_CERT_AUX *aux;
    CRYPTO_RWLOCK *lock;
    volatile int ex_cached;
}  ;
char *i2s_ASN1_OCTET_STRING(X509V3_EXT_METHOD *method,
                            const ASN1_OCTET_STRING *oct)
{
    return OPENSSL_buf2hexstr(oct->data, oct->length);
}
