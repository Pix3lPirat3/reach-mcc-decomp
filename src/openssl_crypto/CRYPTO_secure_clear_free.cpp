typedef unsigned __int64 size_t;
void CRYPTO_free(void *ptr, const char *file, int line);
void CRYPTO_secure_clear_free(void *ptr, size_t num,
                              const char *file, int line);
void OPENSSL_cleanse(void *ptr, size_t len);
void CRYPTO_secure_clear_free(void *ptr, size_t num,
                              const char *file, int line)
{
    if (ptr == ((void *)0))
        return;
    OPENSSL_cleanse(ptr, num);
    CRYPTO_free(ptr, file, line);
}
