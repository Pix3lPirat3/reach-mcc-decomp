typedef struct asn1_string_st ASN1_STRING;
typedef struct asn1_object_st ASN1_OBJECT;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
typedef struct X509_name_entry_st X509_NAME_ENTRY;
ASN1_STRING * X509_NAME_ENTRY_get_data(const X509_NAME_ENTRY *ne);
struct X509_name_entry_st {
    ASN1_OBJECT *object;
    ASN1_STRING *value;
    int set;
    int size;
};
ASN1_STRING *X509_NAME_ENTRY_get_data(const X509_NAME_ENTRY *ne)
{
    if (ne == ((void *)0))
        return ((void *)0);
    return ne->value;
}
