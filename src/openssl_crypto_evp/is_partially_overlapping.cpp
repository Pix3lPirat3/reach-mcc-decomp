typedef unsigned __int64 size_t;
typedef struct rand_drbg_st RAND_DRBG;
typedef size_t (*RAND_DRBG_get_entropy_fn)(RAND_DRBG *drbg,
                                           unsigned char **pout,
                                           int entropy, size_t min_len,
                                           size_t max_len,
                                           int prediction_resistance);
typedef size_t (*RAND_DRBG_get_nonce_fn)(RAND_DRBG *drbg, unsigned char **pout,
                                         int entropy, size_t min_len,
                                         size_t max_len);
int is_partially_overlapping(const void *ptr1, const void *ptr2, int len);
int is_partially_overlapping(const void *ptr1, const void *ptr2, int len)
{
    size_t diff = (size_t)ptr1-(size_t)ptr2;
    int overlapped = (len > 0) & (diff != 0) & ((diff < (size_t)len) |
                                                (diff > (0 - (size_t)len)));
    return overlapped;
}
