typedef unsigned __int64 size_t;
void *CRYPTO_malloc(size_t num, const char *file, int line);
void *CRYPTO_secure_malloc(size_t num, const char *file, int line);
void *CRYPTO_secure_malloc(size_t num, const char *file, int line)
{
    return CRYPTO_malloc(num, file, line);
}
