typedef struct stack_st OPENSSL_STACK;
int OPENSSL_sk_num(const OPENSSL_STACK *);
struct stack_st_X509_ATTRIBUTE;
static  __inline int sk_X509_ATTRIBUTE_num(const struct stack_st_X509_ATTRIBUTE *sk) { return OPENSSL_sk_num((const OPENSSL_STACK *)sk); }
int X509at_get_attr_count(const struct stack_st_X509_ATTRIBUTE *x);
int X509at_get_attr_count(const struct stack_st_X509_ATTRIBUTE *x)
{
    return sk_X509_ATTRIBUTE_num(x);
}
