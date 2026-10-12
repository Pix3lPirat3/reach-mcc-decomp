typedef struct asn1_string_st ASN1_OCTET_STRING;
typedef int ASN1_BOOLEAN;
typedef struct asn1_object_st ASN1_OBJECT;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
typedef struct X509_extension_st X509_EXTENSION;
ASN1_OCTET_STRING *X509_EXTENSION_get_data(X509_EXTENSION *ne);
struct X509_extension_st {
    ASN1_OBJECT *object;
    ASN1_BOOLEAN critical;
    ASN1_OCTET_STRING value;
};
ASN1_OCTET_STRING *X509_EXTENSION_get_data(X509_EXTENSION *ex)
{
    if (ex == ((void *)0))
        return ((void *)0);
    return &ex->value;
}
