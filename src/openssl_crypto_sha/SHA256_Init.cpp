typedef unsigned __int64 size_t;
void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );
typedef struct SHA256state_st {
    unsigned int h[8];
    unsigned int Nl, Nh;
    unsigned int data[16];
    unsigned int num, md_len;
} SHA256_CTX;
int SHA256_Init(SHA256_CTX *c);
int SHA256_Init(SHA256_CTX *c)
{
    memset(c, 0, sizeof(*c));
    c->h[0] = 0x6a09e667UL;
    c->h[1] = 0xbb67ae85UL;
    c->h[2] = 0x3c6ef372UL;
    c->h[3] = 0xa54ff53aUL;
    c->h[4] = 0x510e527fUL;
    c->h[5] = 0x9b05688cUL;
    c->h[6] = 0x1f83d9abUL;
    c->h[7] = 0x5be0cd19UL;
    c->md_len = 32;
    return 1;
}
