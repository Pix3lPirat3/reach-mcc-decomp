typedef unsigned __int64 size_t;
typedef unsigned long long uint64_t;
typedef struct evp_md_st EVP_MD;
typedef struct evp_md_ctx_st EVP_MD_CTX;
typedef struct ossl_init_settings_st OPENSSL_INIT_SETTINGS;
int OPENSSL_init_crypto(uint64_t opts, const OPENSSL_INIT_SETTINGS *settings);
const char *OBJ_NAME_get(const char *name, int type);
const EVP_MD *EVP_get_digestbyname(const char *name);
struct evp_md_st {
    int type;
    int pkey_type;
    int md_size;
    unsigned long flags;
    int (*init) (EVP_MD_CTX *ctx);
    int (*update) (EVP_MD_CTX *ctx, const void *data, size_t count);
    int (*final) (EVP_MD_CTX *ctx, unsigned char *md);
    int (*copy) (EVP_MD_CTX *to, const EVP_MD_CTX *from);
    int (*cleanup) (EVP_MD_CTX *ctx);
    int block_size;
    int ctx_size;
    int (*md_ctrl) (EVP_MD_CTX *ctx, int cmd, int p1, void *p2);
}  ;
const EVP_MD *EVP_get_digestbyname(const char *name)
{
    const EVP_MD *cp;
    if (!OPENSSL_init_crypto(0x00000008L, ((void *)0)))
        return ((void *)0);
    cp = (const EVP_MD *)OBJ_NAME_get(name, 0x01);
    return cp;
}
