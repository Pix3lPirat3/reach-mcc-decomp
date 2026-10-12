typedef struct stack_st OPENSSL_STACK;
typedef int (*OPENSSL_sk_compfunc)(const void *, const void *);
void *OPENSSL_sk_set(OPENSSL_STACK *st, int i, const void *data);
struct stack_st {
    int num;
    const void **data;
    int sorted;
    int num_alloc;
    OPENSSL_sk_compfunc comp;
};
void *OPENSSL_sk_set(OPENSSL_STACK *st, int i, const void *data)
{
    if (st == ((void *)0) || i < 0 || i >= st->num)
        return ((void *)0);
    st->data[i] = data;
    st->sorted = 0;
    return (void *)st->data[i];
}
