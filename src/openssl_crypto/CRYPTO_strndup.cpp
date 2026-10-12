typedef unsigned __int64 size_t;
size_t OPENSSL_strnlen(const char *str, size_t maxlen);
void *CRYPTO_malloc(size_t num, const char *file, int line);
char *CRYPTO_strndup(const char *str, size_t s, const char *file, int line);
void* __cdecl memcpy(
      void* _Dst,
            void const* _Src,
                               size_t      _Size
    );
char *CRYPTO_strndup(const char *str, size_t s, const char* file, int line)
{
    size_t maxlen;
    char *ret;
    if (str == ((void *)0))
        return ((void *)0);
    maxlen = OPENSSL_strnlen(str, s);
    ret = CRYPTO_malloc(maxlen + 1, file, line);
    if (ret) {
        memcpy(ret, str, maxlen);
        ret[maxlen] = '\0';
    }
    return ret;
}
size_t OPENSSL_strnlen(const char *str, size_t maxlen)
{
    const char *p;
    for (p = str; maxlen-- != 0 && *p != '\0'; ++p) ;
    return p - str;
}
