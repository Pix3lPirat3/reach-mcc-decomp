typedef unsigned __int64 size_t;
void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );
typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;
void OPENSSL_cleanse(void *ptr, size_t len);
int EVP_CIPHER_CTX_block_size(const EVP_CIPHER_CTX *ctx);
int EVP_Cipher(EVP_CIPHER_CTX *c,
                          unsigned char *out,
                          const unsigned char *in, unsigned int inl);
typedef struct CMAC_CTX_st CMAC_CTX;
int CMAC_Final(CMAC_CTX *ctx, unsigned char *out, size_t *poutlen);
struct CMAC_CTX_st {
    EVP_CIPHER_CTX *cctx;
    unsigned char k1[32];
    unsigned char k2[32];
    unsigned char tbl[32];
    unsigned char last_block[32];
    int nlast_block;
};
int CMAC_Final(CMAC_CTX *ctx, unsigned char *out, size_t *poutlen)
{
    int i, bl, lb;
    if (ctx->nlast_block == -1)
        return 0;
    bl = EVP_CIPHER_CTX_block_size(ctx->cctx);
    *poutlen = (size_t)bl;
    if (!out)
        return 1;
    lb = ctx->nlast_block;
    if (lb == bl) {
        for (i = 0; i < bl; i++)
            out[i] = ctx->last_block[i] ^ ctx->k1[i];
    } else {
        ctx->last_block[lb] = 0x80;
        if (bl - lb > 1)
            memset(ctx->last_block + lb + 1, 0, bl - lb - 1);
        for (i = 0; i < bl; i++)
            out[i] = ctx->last_block[i] ^ ctx->k2[i];
    }
    if (!EVP_Cipher(ctx->cctx, out, out, bl)) {
        OPENSSL_cleanse(out, bl);
        return 0;
    }
    return 1;
}
