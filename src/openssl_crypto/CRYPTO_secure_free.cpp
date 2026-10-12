void CRYPTO_free(void *ptr, const char *file, int line);
void CRYPTO_secure_free(void *ptr, const char *file, int line);
void CRYPTO_secure_free(void *ptr, const char *file, int line)
{
    CRYPTO_free(ptr, file, line);
}
