typedef unsigned __int64 size_t;
typedef unsigned long long uint64_t;
typedef struct siphash_st SIPHASH;
size_t SipHash_hash_size(SIPHASH *ctx);
struct siphash_st {
    uint64_t total_inlen;
    uint64_t v0;
    uint64_t v1;
    uint64_t v2;
    uint64_t v3;
    unsigned int len;
    int hash_size;
    int crounds;
    int drounds;
    unsigned char leavings[8];
};
size_t SipHash_hash_size(SIPHASH *ctx)
{
    return ctx->hash_size;
}
