typedef struct bignum_st BIGNUM;
typedef struct bignum_ctx BN_CTX;
void BN_CTX_end(BN_CTX *ctx);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
typedef struct bignum_pool_item {
    BIGNUM vals[16];
    struct bignum_pool_item *prev, *next;
} BN_POOL_ITEM;
typedef struct bignum_pool {
    BN_POOL_ITEM *head, *current, *tail;
    unsigned used, size;
} BN_POOL;
static void BN_POOL_release(BN_POOL *, unsigned int);
typedef struct bignum_ctx_stack {
    unsigned int *indexes;
    unsigned int depth, size;
} BN_STACK;
static unsigned int BN_STACK_pop(BN_STACK *);
struct bignum_ctx {
    BN_POOL pool;
    BN_STACK stack;
    unsigned int used;
    int err_stack;
    int too_many;
    int flags;
};
void BN_CTX_end(BN_CTX *ctx)
{
    if (ctx == ((void *)0))
        return;
    ;
    if (ctx->err_stack)
        ctx->err_stack--;
    else {
        unsigned int fp = BN_STACK_pop(&ctx->stack);
        if (fp < ctx->used)
            BN_POOL_release(&ctx->pool, ctx->used - fp);
        ctx->used = fp;
        ctx->too_many = 0;
    }
    ;
}
static unsigned int BN_STACK_pop(BN_STACK *st)
{
    return st->indexes[--(st->depth)];
}
static void BN_POOL_release(BN_POOL *p, unsigned int num)
{
    unsigned int offset = (p->used - 1) % 16;
    p->used -= num;
    while (num--) {
        ;
        if (offset == 0) {
            offset = 16 - 1;
            p->current = p->current->prev;
        } else
            offset--;
    }
}
