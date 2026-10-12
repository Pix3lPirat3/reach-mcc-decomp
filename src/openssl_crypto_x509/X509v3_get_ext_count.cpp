typedef struct stack_st OPENSSL_STACK;
int OPENSSL_sk_num(const OPENSSL_STACK *);
struct stack_st_X509_EXTENSION;
static  __inline int sk_X509_EXTENSION_num(const struct stack_st_X509_EXTENSION *sk) { return OPENSSL_sk_num((const OPENSSL_STACK *)sk); }
int X509v3_get_ext_count(const struct stack_st_X509_EXTENSION *x);
int X509v3_get_ext_count(const struct stack_st_X509_EXTENSION *x)
{
    if (x == ((void *)0))
        return 0;
    return sk_X509_EXTENSION_num(x);
}
