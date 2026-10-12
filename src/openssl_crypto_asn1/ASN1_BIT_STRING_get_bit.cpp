typedef struct asn1_string_st ASN1_BIT_STRING;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
int ASN1_BIT_STRING_get_bit(const ASN1_BIT_STRING *a, int n);
int ASN1_BIT_STRING_get_bit(const ASN1_BIT_STRING *a, int n)
{
    int w, v;
    w = n / 8;
    v = 1 << (7 - (n & 0x07));
    if ((a == ((void *)0)) || (a->length < (w + 1)) || (a->data == ((void *)0)))
        return 0;
    return ((a->data[w] & v) != 0);
}
