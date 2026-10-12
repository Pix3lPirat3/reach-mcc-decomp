typedef unsigned __int64 size_t;
void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );
typedef struct SHAstate_st {
    unsigned int h0, h1, h2, h3, h4;
    unsigned int Nl, Nh;
    unsigned int data[16];
    unsigned int num;
} SHA_CTX;
int SHA1_Init(SHA_CTX *c);
int SHA1_Init(SHA_CTX *c)
{
    memset(c, 0, sizeof(*c));
    c->h0 = 0x67452301UL;
    c->h1 = 0xefcdab89UL;
    c->h2 = 0x98badcfeUL;
    c->h3 = 0x10325476UL;
    c->h4 = 0xc3d2e1f0UL;
    return 1;
}
