typedef unsigned __int64 size_t;
typedef struct asn1_string_st ASN1_STRING;
typedef struct asn1_object_st ASN1_OBJECT;
typedef struct buf_mem_st BUF_MEM;
typedef struct X509_name_st X509_NAME;
struct buf_mem_st {
    size_t length;
    char *data;
    size_t max;
    unsigned long flags;
};
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
typedef struct X509_name_entry_st X509_NAME_ENTRY;
struct stack_st_X509_NAME_ENTRY;
void X509_NAME_ENTRY_free(X509_NAME_ENTRY *a);
int X509_NAME_add_entry(X509_NAME *name, const X509_NAME_ENTRY *ne,
                        int loc, int set);
X509_NAME_ENTRY *X509_NAME_ENTRY_create_by_txt(X509_NAME_ENTRY **ne,
                                               const char *field, int type,
                                               const unsigned char *bytes,
                                               int len);
int X509_NAME_add_entry_by_txt(X509_NAME *name, const char *field, int type,
                               const unsigned char *bytes, int len, int loc,
                               int set);
struct X509_name_entry_st {
    ASN1_OBJECT *object;
    ASN1_STRING *value;
    int set;
    int size;
};
struct X509_name_st {
    struct stack_st_X509_NAME_ENTRY *entries;
    int modified;
    BUF_MEM *bytes;
    unsigned char *canon_enc;
    int canon_enclen;
}  ;
int X509_NAME_add_entry_by_txt(X509_NAME *name, const char *field, int type,
                               const unsigned char *bytes, int len, int loc,
                               int set)
{
    X509_NAME_ENTRY *ne;
    int ret;
    ne = X509_NAME_ENTRY_create_by_txt(((void *)0), field, type, bytes, len);
    if (!ne)
        return 0;
    ret = X509_NAME_add_entry(name, ne, loc, set);
    X509_NAME_ENTRY_free(ne);
    return ret;
}
