typedef struct asn1_string_st ASN1_UTF8STRING;
typedef struct asn1_string_st ASN1_STRING;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
ASN1_STRING *ASN1_STRING_type_new(int type);
ASN1_UTF8STRING *ASN1_UTF8STRING_new(void);
ASN1_UTF8STRING *ASN1_UTF8STRING_new(void) { return ASN1_STRING_type_new(12); }
