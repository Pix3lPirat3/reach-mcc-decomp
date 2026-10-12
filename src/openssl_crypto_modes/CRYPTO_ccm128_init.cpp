typedef unsigned __int64 size_t;
typedef void (*block128_f) (const unsigned char in[16],
                            unsigned char out[16], const void *key);
typedef struct ccm128_context CCM128_CONTEXT;
void CRYPTO_ccm128_init(CCM128_CONTEXT *ctx,
                        unsigned int M, unsigned int L, void *key,
                        block128_f block);
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
void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );
void CRYPTO_ccm128_init(CCM128_CONTEXT *ctx,
                        unsigned int M, unsigned int L, void *key,
                        block128_f block)
{
    memset(ctx->nonce.c, 0, sizeof(ctx->nonce.c));
    ctx->nonce.c[0] = ((u8)(L - 1) & 7) | (u8)(((M - 2) / 2) & 7) << 3;
    ctx->blocks = 0;
    ctx->block = block;
    ctx->key = key;
}
