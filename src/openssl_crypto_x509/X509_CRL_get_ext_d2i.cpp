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
typedef struct asn1_string_st ASN1_TIME;
typedef struct asn1_string_st ASN1_GENERALIZEDTIME;
typedef struct asn1_string_st ASN1_VISIBLESTRING;
typedef struct asn1_string_st ASN1_UTF8STRING;
typedef struct asn1_string_st ASN1_STRING;
typedef int ASN1_BOOLEAN;
typedef struct asn1_object_st ASN1_OBJECT;
typedef struct buf_mem_st BUF_MEM;
typedef struct X509_algor_st X509_ALGOR;
typedef struct X509_crl_st X509_CRL;
typedef struct x509_crl_method_st X509_CRL_METHOD;
typedef struct X509_name_st X509_NAME;
typedef struct AUTHORITY_KEYID_st AUTHORITY_KEYID;
typedef struct ISSUING_DIST_POINT_st ISSUING_DIST_POINT;
typedef void CRYPTO_RWLOCK;
struct buf_mem_st {
    size_t length;
    char *data;
    size_t max;
    unsigned long flags;
};
struct X509_algor_st;
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
struct X509_algor_st {
    ASN1_OBJECT *algorithm;
    ASN1_TYPE *parameter;
}  ;
struct stack_st_X509_NAME_ENTRY;
struct stack_st_X509_EXTENSION;
struct stack_st_X509_REVOKED;
typedef struct X509_crl_info_st X509_CRL_INFO;
void *X509_CRL_get_ext_d2i(const X509_CRL *x, int nid, int *crit, int *idx);
typedef volatile int CRYPTO_REF_COUNT;
struct X509_name_st {
    struct stack_st_X509_NAME_ENTRY *entries;
    int modified;
    BUF_MEM *bytes;
    unsigned char *canon_enc;
    int canon_enclen;
}  ;
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
struct AUTHORITY_KEYID_st {
    ASN1_OCTET_STRING *keyid;
    GENERAL_NAMES *issuer;
    ASN1_INTEGER *serial;
};
struct ISSUING_DIST_POINT_st {
    DIST_POINT_NAME *distpoint;
    int onlyuser;
    int onlyCA;
    ASN1_BIT_STRING *onlysomereasons;
    int indirectCRL;
    int onlyattr;
};
void *X509V3_get_d2i(const struct stack_st_X509_EXTENSION *x, int nid, int *crit,
                     int *idx);
void *X509_CRL_get_ext_d2i(const X509_CRL *x, int nid, int *crit, int *idx)
{
    return X509V3_get_d2i(x->crl.extensions, nid, crit, idx);
}
