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
typedef struct X509_algor_st X509_ALGOR;
typedef struct pkcs8_priv_key_info_st PKCS8_PRIV_KEY_INFO;
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
void ASN1_STRING_set0(ASN1_STRING *str, void *data, int len);
int ASN1_INTEGER_set(ASN1_INTEGER *a, long v);
struct X509_algor_st {
    ASN1_OBJECT *algorithm;
    ASN1_TYPE *parameter;
}  ;
struct stack_st_X509_ATTRIBUTE;
int X509_ALGOR_set0(X509_ALGOR *alg, ASN1_OBJECT *aobj, int ptype,
                    void *pval);
int PKCS8_pkey_set0(PKCS8_PRIV_KEY_INFO *priv, ASN1_OBJECT *aobj,
                    int version, int ptype, void *pval,
                    unsigned char *penc, int penclen);
struct pkcs8_priv_key_info_st {
    ASN1_INTEGER *version;
    X509_ALGOR *pkeyalg;
    ASN1_OCTET_STRING *pkey;
    struct stack_st_X509_ATTRIBUTE *attributes;
};
int PKCS8_pkey_set0(PKCS8_PRIV_KEY_INFO *priv, ASN1_OBJECT *aobj,
                    int version,
                    int ptype, void *pval, unsigned char *penc, int penclen)
{
    if (version >= 0) {
        if (!ASN1_INTEGER_set(priv->version, version))
            return 0;
    }
    if (!X509_ALGOR_set0(priv->pkeyalg, aobj, ptype, pval))
        return 0;
    if (penc)
        ASN1_STRING_set0(priv->pkey, penc, penclen);
    return 1;
}
