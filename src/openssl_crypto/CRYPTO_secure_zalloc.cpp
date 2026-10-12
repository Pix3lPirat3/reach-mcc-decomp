typedef unsigned __int64 size_t;
void *CRYPTO_zalloc(size_t num, const char *file, int line);
void *CRYPTO_secure_zalloc(size_t num, const char *file, int line);
void *CRYPTO_secure_zalloc(size_t num, const char *file, int line)
{
    return CRYPTO_zalloc(num, file, line);
}
