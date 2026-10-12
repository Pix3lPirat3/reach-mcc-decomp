__pragma(warning(disable: 4267))
typedef unsigned __int64 size_t;
typedef unsigned long long uint64_t;
typedef struct siphash_st SIPHASH;
int SipHash_set_hash_size(SIPHASH *ctx, size_t hash_size);
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
static size_t siphash_adjust_hash_size(size_t hash_size)
{
    if (hash_size == 0)
        hash_size = 16;
    return hash_size;
}
int SipHash_set_hash_size(SIPHASH *ctx, size_t hash_size)
{
    hash_size = siphash_adjust_hash_size(hash_size);
    if (hash_size != 8
        && hash_size != 16)
        return 0;
    ctx->hash_size = siphash_adjust_hash_size(ctx->hash_size);
    if ((size_t)ctx->hash_size != hash_size) {
        ctx->v1 ^= 0xee;
        ctx->hash_size = hash_size;
    }
    return 1;
}
