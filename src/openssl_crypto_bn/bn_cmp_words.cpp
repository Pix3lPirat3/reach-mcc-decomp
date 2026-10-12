int bn_cmp_words(const unsigned long long *a, const unsigned long long *b, int n);
int bn_cmp_words(const unsigned long long *a, const unsigned long long *b, int n)
{
    int i;
    unsigned long long aa, bb;
    if (n == 0)
        return 0;
    aa = a[n - 1];
    bb = b[n - 1];
    if (aa != bb)
        return ((aa > bb) ? 1 : -1);
    for (i = n - 2; i >= 0; i--) {
        aa = a[i];
        bb = b[i];
        if (aa != bb)
            return ((aa > bb) ? 1 : -1);
    }
    return 0;
}
