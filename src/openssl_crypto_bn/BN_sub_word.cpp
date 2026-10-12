typedef struct bignum_st BIGNUM;
int BN_is_zero(const BIGNUM *a);
void BN_set_negative(BIGNUM *b, int n);
int BN_add_word(BIGNUM *a, unsigned long long w);
int BN_sub_word(BIGNUM *a, unsigned long long w);
int BN_set_word(BIGNUM *a, unsigned long long w);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
int BN_sub_word(BIGNUM *a, unsigned long long w)
{
    int i;
    ;
    w &= (0xffffffffffffffffLL);
    if (!w)
        return 1;
    if (BN_is_zero(a)) {
        i = BN_set_word(a, w);
        if (i != 0)
            BN_set_negative(a, 1);
        return i;
    }
    if (a->neg) {
        a->neg = 0;
        i = BN_add_word(a, w);
        a->neg = 1;
        return i;
    }
    if ((a->top == 1) && (a->d[0] < w)) {
        a->d[0] = w - a->d[0];
        a->neg = 1;
        return 1;
    }
    i = 0;
    for (;;) {
        if (a->d[i] >= w) {
            a->d[i] -= w;
            break;
        } else {
            a->d[i] = (a->d[i] - w) & (0xffffffffffffffffLL);
            i++;
            w = 1;
        }
    }
    if ((a->d[i] == 0) && (i == (a->top - 1)))
        a->top--;
    ;
    return 1;
}
