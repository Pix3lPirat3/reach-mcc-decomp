typedef unsigned __int64 size_t;
typedef struct {
    union {
        unsigned char c[(512/8)];
        double q[(512/8) / sizeof(double)];
    } H;
    unsigned char data[512 / 8];
    unsigned int bitoff;
    size_t bitlen[(256/8) / sizeof(size_t)];
} WHIRLPOOL_CTX;
int WHIRLPOOL_Init(WHIRLPOOL_CTX *c);
void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );
int WHIRLPOOL_Init(WHIRLPOOL_CTX *c)
{
    memset(c, 0, sizeof(*c));
    return 1;
}
