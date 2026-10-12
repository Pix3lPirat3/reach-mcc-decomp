typedef struct asn1_string_st ASN1_OCTET_STRING;
typedef struct asn1_string_st ASN1_STRING;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
ASN1_STRING *ASN1_STRING_dup(const ASN1_STRING *a);
ASN1_OCTET_STRING *ASN1_OCTET_STRING_dup(const ASN1_OCTET_STRING *a);
ASN1_OCTET_STRING *ASN1_OCTET_STRING_dup(const ASN1_OCTET_STRING *x)
{
    return ASN1_STRING_dup(x);
}
