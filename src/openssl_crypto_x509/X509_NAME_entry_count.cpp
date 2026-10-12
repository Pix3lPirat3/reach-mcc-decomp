typedef unsigned __int64 size_t;
typedef struct stack_st OPENSSL_STACK;
int OPENSSL_sk_num(const OPENSSL_STACK *);
typedef struct buf_mem_st BUF_MEM;
typedef struct X509_name_st X509_NAME;
struct buf_mem_st {
    size_t length;
    char *data;
    size_t max;
    unsigned long flags;
};
struct stack_st_X509_NAME_ENTRY;
static  __inline int sk_X509_NAME_ENTRY_num(const struct stack_st_X509_NAME_ENTRY *sk) { return OPENSSL_sk_num((const OPENSSL_STACK *)sk); }
int X509_NAME_entry_count(const X509_NAME *name);
struct X509_name_st {
    struct stack_st_X509_NAME_ENTRY *entries;
    int modified;
    BUF_MEM *bytes;
    unsigned char *canon_enc;
    int canon_enclen;
}  ;
int X509_NAME_entry_count(const X509_NAME *name)
{
    if (name == ((void *)0))
        return 0;
    return sk_X509_NAME_ENTRY_num(name->entries);
}
