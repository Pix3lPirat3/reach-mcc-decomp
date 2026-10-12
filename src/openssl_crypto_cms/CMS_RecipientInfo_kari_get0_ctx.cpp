typedef unsigned __int64 size_t;
typedef int                int32_t;
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
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;
typedef struct evp_pkey_st EVP_PKEY;
typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;
typedef struct x509_st X509;
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
struct X509_algor_st {
    ASN1_OBJECT *algorithm;
    ASN1_TYPE *parameter;
}  ;
typedef struct CMS_RecipientInfo_st CMS_RecipientInfo;
typedef struct CMS_OtherKeyAttribute_st CMS_OtherKeyAttribute;
struct stack_st_CMS_RecipientEncryptedKey;
EVP_CIPHER_CTX *CMS_RecipientInfo_kari_get0_ctx(CMS_RecipientInfo *ri);
typedef struct CMS_IssuerAndSerialNumber_st CMS_IssuerAndSerialNumber;
typedef struct CMS_SignerIdentifier_st CMS_SignerIdentifier;
typedef struct CMS_KeyTransRecipientInfo_st CMS_KeyTransRecipientInfo;
typedef struct CMS_OriginatorPublicKey_st CMS_OriginatorPublicKey;
typedef struct CMS_OriginatorIdentifierOrKey_st CMS_OriginatorIdentifierOrKey;
typedef struct CMS_KeyAgreeRecipientInfo_st CMS_KeyAgreeRecipientInfo;
typedef struct CMS_KEKIdentifier_st CMS_KEKIdentifier;
typedef struct CMS_KEKRecipientInfo_st CMS_KEKRecipientInfo;
typedef struct CMS_PasswordRecipientInfo_st CMS_PasswordRecipientInfo;
typedef struct CMS_OtherRecipientInfo_st CMS_OtherRecipientInfo;
struct CMS_SignerIdentifier_st {
    int type;
    union {
        CMS_IssuerAndSerialNumber *issuerAndSerialNumber;
        ASN1_OCTET_STRING *subjectKeyIdentifier;
    } d;
};
struct CMS_RecipientInfo_st {
    int type;
    union {
        CMS_KeyTransRecipientInfo *ktri;
        CMS_KeyAgreeRecipientInfo *kari;
        CMS_KEKRecipientInfo *kekri;
        CMS_PasswordRecipientInfo *pwri;
        CMS_OtherRecipientInfo *ori;
    } d;
};
typedef CMS_SignerIdentifier CMS_RecipientIdentifier;
struct CMS_KeyTransRecipientInfo_st {
    int32_t version;
    CMS_RecipientIdentifier *rid;
    X509_ALGOR *keyEncryptionAlgorithm;
    ASN1_OCTET_STRING *encryptedKey;
    X509 *recip;
    EVP_PKEY *pkey;
    EVP_PKEY_CTX *pctx;
};
struct CMS_KeyAgreeRecipientInfo_st {
    int32_t version;
    CMS_OriginatorIdentifierOrKey *originator;
    ASN1_OCTET_STRING *ukm;
    X509_ALGOR *keyEncryptionAlgorithm;
    struct stack_st_CMS_RecipientEncryptedKey *recipientEncryptedKeys;
    EVP_PKEY_CTX *pctx;
    EVP_CIPHER_CTX *ctx;
};
struct CMS_OriginatorIdentifierOrKey_st {
    int type;
    union {
        CMS_IssuerAndSerialNumber *issuerAndSerialNumber;
        ASN1_OCTET_STRING *subjectKeyIdentifier;
        CMS_OriginatorPublicKey *originatorKey;
    } d;
};
struct CMS_OriginatorPublicKey_st {
    X509_ALGOR *algorithm;
    ASN1_BIT_STRING *publicKey;
};
struct CMS_KEKRecipientInfo_st {
    int32_t version;
    CMS_KEKIdentifier *kekid;
    X509_ALGOR *keyEncryptionAlgorithm;
    ASN1_OCTET_STRING *encryptedKey;
    unsigned char *key;
    size_t keylen;
};
struct CMS_KEKIdentifier_st {
    ASN1_OCTET_STRING *keyIdentifier;
    ASN1_GENERALIZEDTIME *date;
    CMS_OtherKeyAttribute *other;
};
struct CMS_PasswordRecipientInfo_st {
    int32_t version;
    X509_ALGOR *keyDerivationAlgorithm;
    X509_ALGOR *keyEncryptionAlgorithm;
    ASN1_OCTET_STRING *encryptedKey;
    unsigned char *pass;
    size_t passlen;
};
struct CMS_OtherRecipientInfo_st {
    ASN1_OBJECT *oriType;
    ASN1_TYPE *oriValue;
};
struct CMS_IssuerAndSerialNumber_st {
    X509_NAME *issuer;
    ASN1_INTEGER *serialNumber;
};
struct CMS_OtherKeyAttribute_st {
    ASN1_OBJECT *keyAttrId;
    ASN1_TYPE *keyAttr;
};
struct asn1_object_st {
    const char *sn, *ln;
    int nid;
    int length;
    const unsigned char *data;
    int flags;
};
EVP_CIPHER_CTX *CMS_RecipientInfo_kari_get0_ctx(CMS_RecipientInfo *ri)
{
    if (ri->type == 1)
        return ri->d.kari->ctx;
    return ((void *)0);
}
