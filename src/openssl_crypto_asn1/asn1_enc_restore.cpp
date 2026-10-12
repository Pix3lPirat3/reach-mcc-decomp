typedef unsigned __int64 size_t;
void* __cdecl memcpy(
      void* _Dst,
            void const* _Src,
                               size_t      _Size
    );
typedef struct ASN1_ITEM_st ASN1_ITEM;
typedef struct ASN1_ENCODING_st {
    unsigned char *enc;
    long len;
    int modified;
} ASN1_ENCODING;
typedef struct ASN1_TEMPLATE_st ASN1_TEMPLATE;
typedef struct ASN1_VALUE_st ASN1_VALUE;
typedef const ASN1_ITEM *ASN1_ITEM_EXP (void);
struct ASN1_TEMPLATE_st {
    unsigned long flags;
    long tag;
    unsigned long offset;
    const char *field_name;
    ASN1_ITEM_EXP *item;
};
struct ASN1_ITEM_st {
    char itype;
    long utype;
    const ASN1_TEMPLATE *templates;
    long tcount;
    const void *funcs;
    long size;
    const char *sname;
};
typedef int ASN1_aux_cb(int operation, ASN1_VALUE **in, const ASN1_ITEM *it,
                        void *exarg);
typedef struct ASN1_AUX_st {
    void *app_data;
    int flags;
    int ref_offset;
    int ref_lock;
    ASN1_aux_cb *asn1_cb;
    int enc_offset;
} ASN1_AUX;
int asn1_enc_restore(int *len, unsigned char **out, ASN1_VALUE **pval,
                     const ASN1_ITEM *it);
static ASN1_ENCODING *asn1_get_enc_ptr(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
    const ASN1_AUX *aux;
    if (!pval || !*pval)
        return ((void *)0);
    aux = it->funcs;
    if (!aux || !(aux->flags & 2))
        return ((void *)0);
    return (void *)(((char *) *pval) + aux->enc_offset);
}
int asn1_enc_restore(int *len, unsigned char **out, ASN1_VALUE **pval,
                     const ASN1_ITEM *it)
{
    ASN1_ENCODING *enc;
    enc = asn1_get_enc_ptr(pval, it);
    if (!enc || enc->modified)
        return 0;
    if (out) {
        memcpy(*out, enc->enc, enc->len);
        *out += enc->len;
    }
    if (len)
        *len = enc->len;
    return 1;
}
