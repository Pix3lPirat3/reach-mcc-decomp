typedef struct asn1_string_st ASN1_OCTET_STRING;
typedef struct asn1_string_st ASN1_STRING;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
void ASN1_STRING_free(ASN1_STRING *a);
void ASN1_OCTET_STRING_free(ASN1_OCTET_STRING *a);
void ASN1_OCTET_STRING_free(ASN1_OCTET_STRING *x) { ASN1_STRING_free(x); }
