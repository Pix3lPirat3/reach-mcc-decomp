typedef struct asn1_string_st ASN1_BIT_STRING;
typedef struct asn1_string_st ASN1_STRING;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
ASN1_STRING *ASN1_STRING_type_new(int type);
ASN1_BIT_STRING *ASN1_BIT_STRING_new(void);
ASN1_BIT_STRING *ASN1_BIT_STRING_new(void) { return ASN1_STRING_type_new(3); }
