typedef struct stack_st OPENSSL_STACK;
int OPENSSL_sk_num(const OPENSSL_STACK *);
void *OPENSSL_sk_value(const OPENSSL_STACK *, int);
typedef struct asn1_object_st ASN1_OBJECT;
struct stack_st_ASN1_TYPE;
ASN1_OBJECT *OBJ_nid2obj(int n);
int OBJ_cmp(const ASN1_OBJECT *a, const ASN1_OBJECT *b);
typedef struct x509_attributes_st X509_ATTRIBUTE;
struct stack_st_X509_ATTRIBUTE;
static  __inline int sk_X509_ATTRIBUTE_num(const struct stack_st_X509_ATTRIBUTE *sk) { return OPENSSL_sk_num((const OPENSSL_STACK *)sk); }
static  __inline X509_ATTRIBUTE *sk_X509_ATTRIBUTE_value(const struct stack_st_X509_ATTRIBUTE *sk, int idx) { return (X509_ATTRIBUTE *)OPENSSL_sk_value((const OPENSSL_STACK *)sk, idx); }
int X509at_get_attr_by_NID(const struct stack_st_X509_ATTRIBUTE *x, int nid,
                           int lastpos);
int X509at_get_attr_by_OBJ(const struct stack_st_X509_ATTRIBUTE *sk,
                           const ASN1_OBJECT *obj, int lastpos);
struct x509_attributes_st {
    ASN1_OBJECT *object;
    struct stack_st_ASN1_TYPE *set;
};
int X509at_get_attr_by_NID(const struct stack_st_X509_ATTRIBUTE *x, int nid,
                           int lastpos)
{
    const ASN1_OBJECT *obj = OBJ_nid2obj(nid);
    if (obj == ((void *)0))
        return -2;
    return X509at_get_attr_by_OBJ(x, obj, lastpos);
}
int X509at_get_attr_by_OBJ(const struct stack_st_X509_ATTRIBUTE *sk,
                           const ASN1_OBJECT *obj, int lastpos)
{
    int n;
    X509_ATTRIBUTE *ex;
    if (sk == ((void *)0))
        return -1;
    lastpos++;
    if (lastpos < 0)
        lastpos = 0;
    n = sk_X509_ATTRIBUTE_num(sk);
    for (; lastpos < n; lastpos++) {
        ex = sk_X509_ATTRIBUTE_value(sk, lastpos);
        if (OBJ_cmp(ex->object, obj) == 0)
            return lastpos;
    }
    return -1;
}
