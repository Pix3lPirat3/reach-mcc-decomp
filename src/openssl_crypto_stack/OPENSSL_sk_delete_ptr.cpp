__pragma(warning(disable: 4090))
typedef unsigned __int64 size_t;
void* __cdecl memmove(
      void*       _Dst,
            void const* _Src,
                                   size_t      _Size
    );
typedef struct stack_st OPENSSL_STACK;
typedef int (*OPENSSL_sk_compfunc)(const void *, const void *);
void *OPENSSL_sk_delete_ptr(OPENSSL_STACK *st, const void *p);
struct stack_st {
    int num;
    const void **data;
    int sorted;
    int num_alloc;
    OPENSSL_sk_compfunc comp;
};
static __inline void *internal_delete(OPENSSL_STACK *st, int loc)
{
    const void *ret = st->data[loc];
    if (loc != st->num - 1)
         memmove(&st->data[loc], &st->data[loc + 1],
                 sizeof(st->data[0]) * (st->num - loc - 1));
    st->num--;
    return (void *)ret;
}
void *OPENSSL_sk_delete_ptr(OPENSSL_STACK *st, const void *p)
{
    int i;
    for (i = 0; i < st->num; i++)
        if (st->data[i] == p)
            return internal_delete(st, i);
    return ((void *)0);
}
