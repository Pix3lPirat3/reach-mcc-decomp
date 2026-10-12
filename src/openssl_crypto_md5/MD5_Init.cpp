typedef unsigned __int64 size_t;
void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );
typedef struct MD5state_st {
    unsigned int A, B, C, D;
    unsigned int Nl, Nh;
    unsigned int data[(64/4)];
    unsigned int num;
} MD5_CTX;
int MD5_Init(MD5_CTX *c);
int MD5_Init(MD5_CTX *c)
{
    memset(c, 0, sizeof(*c));
    c->A = (unsigned long)0x67452301L;
    c->B = (unsigned long)0xefcdab89L;
    c->C = (unsigned long)0x98badcfeL;
    c->D = (unsigned long)0x10325476L;
    return 1;
}
