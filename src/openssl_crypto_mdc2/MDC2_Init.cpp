typedef unsigned __int64 size_t;
void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );
typedef unsigned char DES_cblock[8];
typedef struct mdc2_ctx_st {
    unsigned int num;
    unsigned char data[8];
    DES_cblock h, hh;
    int pad_type;
} MDC2_CTX;
int MDC2_Init(MDC2_CTX *c);
int MDC2_Init(MDC2_CTX *c)
{
    c->num = 0;
    c->pad_type = 1;
    memset(&(c->h[0]), 0x52, 8);
    memset(&(c->hh[0]), 0x25, 8);
    return 1;
}
