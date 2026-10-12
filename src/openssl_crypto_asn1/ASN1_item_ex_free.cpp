typedef struct ASN1_ITEM_st ASN1_ITEM;
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
void ASN1_item_ex_free(ASN1_VALUE **pval, const ASN1_ITEM *it);
void asn1_item_embed_free(ASN1_VALUE **pval, const ASN1_ITEM *it, int embed);
void ASN1_item_ex_free(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
    asn1_item_embed_free(pval, it, 0);
}
