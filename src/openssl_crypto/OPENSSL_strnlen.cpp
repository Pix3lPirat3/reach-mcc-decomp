typedef unsigned __int64 size_t;
size_t OPENSSL_strnlen(const char *str, size_t maxlen);
size_t OPENSSL_strnlen(const char *str, size_t maxlen)
{
    const char *p;
    for (p = str; maxlen-- != 0 && *p != '\0'; ++p) ;
    return p - str;
}
