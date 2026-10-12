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
typedef struct evp_pkey_st EVP_PKEY;
typedef struct X509_algor_st X509_ALGOR;
typedef struct X509_name_st X509_NAME;
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
int ASN1_STRING_set(ASN1_STRING *str, const void *data, int len);
ASN1_OCTET_STRING *ASN1_OCTET_STRING_new(void);
void ASN1_OCTET_STRING_free(ASN1_OCTET_STRING *a);
struct X509_algor_st {
    ASN1_OBJECT *algorithm;
    ASN1_TYPE *parameter;
}  ;
struct stack_st_X509_ATTRIBUTE;
typedef struct pkcs7_issuer_and_serial_st {
    X509_NAME *issuer;
    ASN1_INTEGER *serial;
} PKCS7_ISSUER_AND_SERIAL;
typedef struct pkcs7_signer_info_st {
    ASN1_INTEGER *version;
    PKCS7_ISSUER_AND_SERIAL *issuer_and_serial;
    X509_ALGOR *digest_alg;
    struct stack_st_X509_ATTRIBUTE *auth_attr;
    X509_ALGOR *digest_enc_alg;
    ASN1_OCTET_STRING *enc_digest;
    struct stack_st_X509_ATTRIBUTE *unauth_attr;
    EVP_PKEY *pkey;
} PKCS7_SIGNER_INFO;
int PKCS7_add_signed_attribute(PKCS7_SIGNER_INFO *p7si, int nid, int type,
                               void *data);
int PKCS7_add1_attrib_digest(PKCS7_SIGNER_INFO *si,
                             const unsigned char *md, int mdlen);
int PKCS7_add1_attrib_digest(PKCS7_SIGNER_INFO *si,
                             const unsigned char *md, int mdlen)
{
    ASN1_OCTET_STRING *os;
    os = ASN1_OCTET_STRING_new();
    if (os == ((void *)0))
        return 0;
    if (!ASN1_STRING_set(os, md, mdlen)
        || !PKCS7_add_signed_attribute(si, 51,
                                       4, os)) {
        ASN1_OCTET_STRING_free(os);
        return 0;
    }
    return 1;
}
