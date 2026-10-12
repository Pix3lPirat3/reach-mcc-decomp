typedef unsigned __int64 size_t;
typedef struct evp_md_st EVP_MD;
typedef struct evp_md_ctx_st EVP_MD_CTX;
typedef struct hmac_ctx_st HMAC_CTX;
int EVP_DigestUpdate(EVP_MD_CTX *ctx, const void *d,
                                size_t cnt);
int HMAC_Update(HMAC_CTX *ctx, const unsigned char *data,
                           size_t len);
struct hmac_ctx_st {
    const EVP_MD *md;
    EVP_MD_CTX *md_ctx;
    EVP_MD_CTX *i_ctx;
    EVP_MD_CTX *o_ctx;
    unsigned int key_length;
    unsigned char key[144];
};
int HMAC_Update(HMAC_CTX *ctx, const unsigned char *data, size_t len)
{
    if (!ctx->md)
        return 0;
    return EVP_DigestUpdate(ctx->md_ctx, data, len);
}
