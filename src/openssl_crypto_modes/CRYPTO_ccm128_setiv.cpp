typedef unsigned __int64 size_t;
typedef void (*block128_f) (const unsigned char in[16],
                            unsigned char out[16], const void *key);
typedef struct ccm128_context CCM128_CONTEXT;
int CRYPTO_ccm128_setiv(CCM128_CONTEXT *ctx, const unsigned char *nonce,
                        size_t nlen, size_t mlen);
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
int CRYPTO_ccm128_setiv(CCM128_CONTEXT *ctx,
                        const unsigned char *nonce, size_t nlen, size_t mlen)
{
    unsigned int L = ctx->nonce.c[0] & 7;
    if (nlen < (14 - L))
        return -1;
    if (sizeof(mlen) == 8 && L >= 3) {
        ctx->nonce.c[8] = (u8)(mlen >> (56 % (sizeof(mlen) * 8)));
        ctx->nonce.c[9] = (u8)(mlen >> (48 % (sizeof(mlen) * 8)));
        ctx->nonce.c[10] = (u8)(mlen >> (40 % (sizeof(mlen) * 8)));
        ctx->nonce.c[11] = (u8)(mlen >> (32 % (sizeof(mlen) * 8)));
    } else
        ctx->nonce.u[1] = 0;
    ctx->nonce.c[12] = (u8)(mlen >> 24);
    ctx->nonce.c[13] = (u8)(mlen >> 16);
    ctx->nonce.c[14] = (u8)(mlen >> 8);
    ctx->nonce.c[15] = (u8)mlen;
    ctx->nonce.c[0] &= ~0x40;
    memcpy(&ctx->nonce.c[1], nonce, 14 - L);
    return 0;
}
