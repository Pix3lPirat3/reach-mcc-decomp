typedef struct stack_st OPENSSL_STACK;
typedef int (*OPENSSL_sk_compfunc)(const void *, const void *);
int OPENSSL_sk_insert(OPENSSL_STACK *sk, const void *data, int where);
int OPENSSL_sk_push(OPENSSL_STACK *st, const void *data);
struct stack_st {
    int num;
    const void **data;
    int sorted;
    int num_alloc;
    OPENSSL_sk_compfunc comp;
};
int OPENSSL_sk_push(OPENSSL_STACK *st, const void *data)
{
    if (st == ((void *)0))
        return -1;
    return OPENSSL_sk_insert(st, data, st->num);
}
