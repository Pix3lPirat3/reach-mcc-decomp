typedef struct bignum_st BIGNUM;
int BN_hex2bn(BIGNUM **a, const char *str);
int BN_dec2bn(BIGNUM **a, const char *str);
int BN_asc2bn(BIGNUM **a, const char *str);
struct bignum_st {
    unsigned long long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};
int BN_asc2bn(BIGNUM **bn, const char *a)
{
    const char *p = a;
    if (*p == '-')
        p++;
    if (p[0] == '0' && (p[1] == 'X' || p[1] == 'x')) {
        if (!BN_hex2bn(bn, p + 2))
            return 0;
    } else {
        if (!BN_dec2bn(bn, p))
            return 0;
    }
    if (*a == '-' && (*bn)->top != 0)
        (*bn)->neg = 1;
    return 1;
}
