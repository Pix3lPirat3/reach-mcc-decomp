typedef struct asn1_string_st ASN1_INTEGER;
typedef struct asn1_string_st ASN1_STRING;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
int ASN1_STRING_cmp(const ASN1_STRING *a, const ASN1_STRING *b);
int ASN1_INTEGER_cmp(const ASN1_INTEGER *x, const ASN1_INTEGER *y);
int ASN1_INTEGER_cmp(const ASN1_INTEGER *x, const ASN1_INTEGER *y)
{
    int neg, ret;
    neg = x->type & 0x100;
    if (neg != (y->type & 0x100)) {
        if (neg)
            return -1;
        else
            return 1;
    }
    ret = ASN1_STRING_cmp(x, y);
    if (neg)
        return -ret;
    else
        return ret;
}
