typedef unsigned __int64 size_t;
typedef struct asn1_object_st ASN1_OBJECT;
typedef struct buf_mem_st BUF_MEM;
typedef struct X509_name_st X509_NAME;
struct buf_mem_st {
    size_t length;
    char *data;
    size_t max;
    unsigned long flags;
};
ASN1_OBJECT *OBJ_nid2obj(int n);
struct stack_st_X509_NAME_ENTRY;
int X509_NAME_get_index_by_NID(X509_NAME *name, int nid, int lastpos);
int X509_NAME_get_index_by_OBJ(X509_NAME *name, const ASN1_OBJECT *obj,
                               int lastpos);
struct X509_name_st {
    struct stack_st_X509_NAME_ENTRY *entries;
    int modified;
    BUF_MEM *bytes;
    unsigned char *canon_enc;
    int canon_enclen;
}  ;
int X509_NAME_get_index_by_NID(X509_NAME *name, int nid, int lastpos)
{
    ASN1_OBJECT *obj;
    obj = OBJ_nid2obj(nid);
    if (obj == ((void *)0))
        return -2;
    return X509_NAME_get_index_by_OBJ(name, obj, lastpos);
}
