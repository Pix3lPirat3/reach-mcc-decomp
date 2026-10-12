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
int OBJ_obj2nid(const ASN1_OBJECT *o);
typedef struct X509_sig_st X509_SIG;
struct stack_st_X509_ATTRIBUTE;
typedef struct PKCS12_SAFEBAG_st PKCS12_SAFEBAG;
struct stack_st_PKCS12_SAFEBAG;
const struct stack_st_PKCS12_SAFEBAG *
PKCS12_SAFEBAG_get0_safes(const PKCS12_SAFEBAG *bag);
struct PKCS12_SAFEBAG_st {
    ASN1_OBJECT *type;
    union {
        struct pkcs12_bag_st *bag;
        struct pkcs8_priv_key_info_st *keybag;
        X509_SIG *shkeybag;
        struct stack_st_PKCS12_SAFEBAG *safes;
        ASN1_TYPE *other;
    } value;
    struct stack_st_X509_ATTRIBUTE *attrib;
};
struct pkcs12_bag_st {
    ASN1_OBJECT *type;
    union {
        ASN1_OCTET_STRING *x509cert;
        ASN1_OCTET_STRING *x509crl;
        ASN1_OCTET_STRING *octet;
        ASN1_IA5STRING *sdsicert;
        ASN1_TYPE *other;
    } value;
};
const struct stack_st_PKCS12_SAFEBAG *
PKCS12_SAFEBAG_get0_safes(const PKCS12_SAFEBAG *bag)
{
    if (OBJ_obj2nid(bag->type) != 155)
        return ((void *)0);
    return bag->value.safes;
}
