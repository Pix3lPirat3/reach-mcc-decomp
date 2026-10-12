typedef unsigned __int64 size_t;
typedef struct buf_mem_st BUF_MEM;
typedef struct evp_pkey_st EVP_PKEY;
typedef struct x509_st X509;
typedef struct X509_crl_st X509_CRL;
typedef struct ossl_store_info_st OSSL_STORE_INFO;
struct buf_mem_st {
    size_t length;
    char *data;
    size_t max;
    unsigned long flags;
};
struct ossl_store_info_st {
    int type;
    union {
        void *data;
        struct {
            BUF_MEM *blob;
            char *pem_name;
        } embedded;
        struct {
            char *name;
            char *desc;
        } name;
        EVP_PKEY *params;
        EVP_PKEY *pkey;
        X509 *x509;
        X509_CRL *crl;
    } _;
};
char *ossl_store_info_get0_EMBEDDED_pem_name(OSSL_STORE_INFO *info);
char *ossl_store_info_get0_EMBEDDED_pem_name(OSSL_STORE_INFO *info)
{
    if (info->type == -1)
        return info->_.embedded.pem_name;
    return ((void *)0);
}
