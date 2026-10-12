typedef unsigned __int64 size_t;
typedef void (*block128_f) (const unsigned char in[16],
                            unsigned char out[16], const void *key);
typedef struct ccm128_context CCM128_CONTEXT;
size_t CRYPTO_ccm128_tag(CCM128_CONTEXT *ctx, unsigned char *tag, size_t len);
typedef unsigned __int64 u64;
typedef unsigned char u8;
struct ccm128_context {
    union {
        u64 u[2];
        u8 c[16];
    } nonce, cmac;
    u64 blocks;
    block128_f block;
    void *key;
};
void* __cdecl memcpy(
      void* _Dst,
            void const* _Src,
                               size_t      _Size
    );
size_t CRYPTO_ccm128_tag(CCM128_CONTEXT *ctx, unsigned char *tag, size_t len)
{
    unsigned int M = (ctx->nonce.c[0] >> 3) & 7;
    M *= 2;
    M += 2;
    if (len != M)
        return 0;
    memcpy(tag, ctx->cmac.c, M);
    return M;
}
