typedef struct asn1_string_st ASN1_TIME;
typedef struct asn1_string_st ASN1_GENERALIZEDTIME;
typedef struct bio_st BIO;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
int ASN1_GENERALIZEDTIME_print(BIO *fp, const ASN1_GENERALIZEDTIME *a);
int ASN1_TIME_print(BIO *fp, const ASN1_TIME *a);
int ASN1_GENERALIZEDTIME_print(BIO *bp, const ASN1_GENERALIZEDTIME *tm)
{
    if (tm->type != 24)
        return 0;
    return ASN1_TIME_print(bp, tm);
}
