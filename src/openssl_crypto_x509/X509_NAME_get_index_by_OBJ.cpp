typedef unsigned __int64 size_t;
typedef struct stack_st OPENSSL_STACK;
int OPENSSL_sk_num(const OPENSSL_STACK *);
void *OPENSSL_sk_value(const OPENSSL_STACK *, int);
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
int OBJ_cmp(const ASN1_OBJECT *a, const ASN1_OBJECT *b);
typedef struct X509_name_entry_st X509_NAME_ENTRY;
struct stack_st_X509_NAME_ENTRY;
static  __inline int sk_X509_NAME_ENTRY_num(const struct stack_st_X509_NAME_ENTRY *sk) { return OPENSSL_sk_num((const OPENSSL_STACK *)sk); }
static  __inline X509_NAME_ENTRY *sk_X509_NAME_ENTRY_value(const struct stack_st_X509_NAME_ENTRY *sk, int idx) { return (X509_NAME_ENTRY *)OPENSSL_sk_value((const OPENSSL_STACK *)sk, idx); }
int X509_NAME_get_index_by_OBJ(X509_NAME *name, const ASN1_OBJECT *obj,
                               int lastpos);
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
int X509_NAME_get_index_by_OBJ(X509_NAME *name, const ASN1_OBJECT *obj, int lastpos)
{
    int n;
    X509_NAME_ENTRY *ne;
    struct stack_st_X509_NAME_ENTRY *sk;
    if (name == ((void *)0))
        return -1;
    if (lastpos < 0)
        lastpos = -1;
    sk = name->entries;
    n = sk_X509_NAME_ENTRY_num(sk);
    for (lastpos++; lastpos < n; lastpos++) {
        ne = sk_X509_NAME_ENTRY_value(sk, lastpos);
        if (OBJ_cmp(ne->object, obj) == 0)
            return lastpos;
    }
    return -1;
}
