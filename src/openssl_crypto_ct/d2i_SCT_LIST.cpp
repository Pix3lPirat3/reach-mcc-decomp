typedef unsigned __int64 size_t;
typedef struct asn1_string_st ASN1_OCTET_STRING;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
void ASN1_OCTET_STRING_free(ASN1_OCTET_STRING *a);
ASN1_OCTET_STRING *d2i_ASN1_OCTET_STRING(ASN1_OCTET_STRING **a, const unsigned char **in, long len);
struct stack_st_SCT;
struct stack_st_SCT *o2i_SCT_LIST(struct stack_st_SCT **a, const unsigned char **pp,
                            size_t len);
struct stack_st_SCT *d2i_SCT_LIST(struct stack_st_SCT **a, const unsigned char **pp,
                            long len);
struct stack_st_SCT *d2i_SCT_LIST(struct stack_st_SCT **a, const unsigned char **pp,
                            long len)
{
    ASN1_OCTET_STRING *oct = ((void *)0);
    struct stack_st_SCT *sk = ((void *)0);
    const unsigned char *p;
    p = *pp;
    if (d2i_ASN1_OCTET_STRING(&oct, &p, len) == ((void *)0))
        return ((void *)0);
    p = oct->data;
    if ((sk = o2i_SCT_LIST(a, &p, oct->length)) != ((void *)0))
        *pp += len;
    ASN1_OCTET_STRING_free(oct);
    return sk;
}
