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
typedef struct bio_st BIO;
typedef struct evp_cipher_st EVP_CIPHER;
typedef struct X509_algor_st X509_ALGOR;
struct X509_algor_st;
struct stack_st_X509_ALGOR;
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
struct stack_st_X509_ATTRIBUTE;
typedef struct CMS_ContentInfo_st CMS_ContentInfo;
struct stack_st_CMS_SignerInfo;
struct stack_st_CMS_RecipientInfo;
struct stack_st_CMS_RevocationInfoChoice;
typedef struct CMS_EncapsulatedContentInfo_st CMS_EncapsulatedContentInfo;
typedef struct CMS_SignedData_st CMS_SignedData;
typedef struct CMS_OriginatorInfo_st CMS_OriginatorInfo;
typedef struct CMS_EncryptedContentInfo_st CMS_EncryptedContentInfo;
typedef struct CMS_EnvelopedData_st CMS_EnvelopedData;
typedef struct CMS_DigestedData_st CMS_DigestedData;
typedef struct CMS_EncryptedData_st CMS_EncryptedData;
typedef struct CMS_AuthenticatedData_st CMS_AuthenticatedData;
typedef struct CMS_CompressedData_st CMS_CompressedData;
struct CMS_ContentInfo_st {
    ASN1_OBJECT *contentType;
    union {
        ASN1_OCTET_STRING *data;
        CMS_SignedData *signedData;
        CMS_EnvelopedData *envelopedData;
        CMS_DigestedData *digestedData;
        CMS_EncryptedData *encryptedData;
        CMS_AuthenticatedData *authenticatedData;
        CMS_CompressedData *compressedData;
        ASN1_TYPE *other;
        void *otherData;
    } d;
};
struct stack_st_CMS_CertificateChoices;
struct CMS_SignedData_st {
    int32_t version;
    struct stack_st_X509_ALGOR *digestAlgorithms;
    CMS_EncapsulatedContentInfo *encapContentInfo;
    struct stack_st_CMS_CertificateChoices *certificates;
    struct stack_st_CMS_RevocationInfoChoice *crls;
    struct stack_st_CMS_SignerInfo *signerInfos;
};
struct CMS_EncapsulatedContentInfo_st {
    ASN1_OBJECT *eContentType;
    ASN1_OCTET_STRING *eContent;
    int partial;
};
struct CMS_EnvelopedData_st {
    int32_t version;
    CMS_OriginatorInfo *originatorInfo;
    struct stack_st_CMS_RecipientInfo *recipientInfos;
    CMS_EncryptedContentInfo *encryptedContentInfo;
    struct stack_st_X509_ATTRIBUTE *unprotectedAttrs;
};
struct CMS_OriginatorInfo_st {
    struct stack_st_CMS_CertificateChoices *certificates;
    struct stack_st_CMS_RevocationInfoChoice *crls;
};
struct CMS_EncryptedContentInfo_st {
    ASN1_OBJECT *contentType;
    X509_ALGOR *contentEncryptionAlgorithm;
    ASN1_OCTET_STRING *encryptedContent;
    const EVP_CIPHER *cipher;
    unsigned char *key;
    size_t keylen;
    int debug;
};
struct CMS_DigestedData_st {
    int32_t version;
    X509_ALGOR *digestAlgorithm;
    CMS_EncapsulatedContentInfo *encapContentInfo;
    ASN1_OCTET_STRING *digest;
};
struct CMS_EncryptedData_st {
    int32_t version;
    CMS_EncryptedContentInfo *encryptedContentInfo;
    struct stack_st_X509_ATTRIBUTE *unprotectedAttrs;
};
struct CMS_AuthenticatedData_st {
    int32_t version;
    CMS_OriginatorInfo *originatorInfo;
    struct stack_st_CMS_RecipientInfo *recipientInfos;
    X509_ALGOR *macAlgorithm;
    X509_ALGOR *digestAlgorithm;
    CMS_EncapsulatedContentInfo *encapContentInfo;
    struct stack_st_X509_ATTRIBUTE *authAttrs;
    ASN1_OCTET_STRING *mac;
    struct stack_st_X509_ATTRIBUTE *unauthAttrs;
};
struct CMS_CompressedData_st {
    int32_t version;
    X509_ALGOR *compressionAlgorithm;
    struct stack_st_CMS_RecipientInfo *recipientInfos;
    CMS_EncapsulatedContentInfo *encapContentInfo;
};
BIO *cms_DigestedData_init_bio(CMS_ContentInfo *cms);
BIO *cms_DigestAlgorithm_init_bio(X509_ALGOR *digestAlgorithm);
BIO *cms_DigestedData_init_bio(CMS_ContentInfo *cms)
{
    CMS_DigestedData *dd;
    dd = cms->d.digestedData;
    return cms_DigestAlgorithm_init_bio(dd->digestAlgorithm);
}
