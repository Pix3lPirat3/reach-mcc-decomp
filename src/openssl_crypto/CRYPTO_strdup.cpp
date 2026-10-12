typedef unsigned __int64 size_t;
void *CRYPTO_malloc(size_t num, const char *file, int line);
char *CRYPTO_strdup(const char *str, const char *file, int line);
char* __cdecl strcpy( char *_Destination,  char const* _Source);
static __inline unsigned int _strlen31(const char *str)
{
    unsigned int len = 0;
    while (*str && len < 0x80000000U)
        str++, len++;
    return len & 0x7FFFFFFF;
}
char *CRYPTO_strdup(const char *str, const char* file, int line)
{
    char *ret;
    if (str == ((void *)0))
        return ((void *)0);
    ret = CRYPTO_malloc(_strlen31(str) + 1, file, line);
    if (ret != ((void *)0))
        strcpy(ret, str);
    return ret;
}
