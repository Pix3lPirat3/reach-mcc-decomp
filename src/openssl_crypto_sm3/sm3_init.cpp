typedef unsigned __int64 size_t;
void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );
typedef struct SM3state_st {
   unsigned int A, B, C, D, E, F, G, H;
   unsigned int Nl, Nh;
   unsigned int data[(64/4)];
   unsigned int num;
} SM3_CTX;
int sm3_init(SM3_CTX *c);
int sm3_init(SM3_CTX *c)
{
    memset(c, 0, sizeof(*c));
    c->A = 0x7380166fUL;
    c->B = 0x4914b2b9UL;
    c->C = 0x172442d7UL;
    c->D = 0xda8a0600UL;
    c->E = 0xa96f30bcUL;
    c->F = 0x163138aaUL;
    c->G = 0xe38dee4dUL;
    c->H = 0xb0fb0e4eUL;
    return 1;
}
