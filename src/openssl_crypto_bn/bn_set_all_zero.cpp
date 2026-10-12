typedef struct bignum_st BIGNUM;
void bn_set_all_zero(BIGNUM *a);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
void bn_set_all_zero(BIGNUM *a)
{
    int i;
    for (i = a->top; i < a->dmax; i++)
        a->d[i] = 0;
}
