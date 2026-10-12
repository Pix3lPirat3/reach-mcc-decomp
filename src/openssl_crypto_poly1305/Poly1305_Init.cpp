typedef unsigned __int64 size_t;
typedef struct poly1305_context POLY1305;
void Poly1305_Init(POLY1305 *ctx, const unsigned char key[32]);
typedef void (*poly1305_blocks_f) (void *ctx, const unsigned char *inp,
                                   size_t len, unsigned int padbit);
typedef void (*poly1305_emit_f) (void *ctx, unsigned char mac[16],
                                 const unsigned int nonce[4]);
struct poly1305_context {
    double opaque[24];
    unsigned int nonce[4];
    unsigned char data[16];
    size_t num;
    struct {
        poly1305_blocks_f blocks;
        poly1305_emit_f emit;
    } func;
};
static unsigned int U8TOU32(const unsigned char *p)
{
    return (((unsigned int)(p[0] & 0xff)) |
            ((unsigned int)(p[1] & 0xff) << 8) |
            ((unsigned int)(p[2] & 0xff) << 16) |
            ((unsigned int)(p[3] & 0xff) << 24));
}
typedef unsigned int u32;
typedef struct {
    u32 h[5];
    u32 r[4];
} poly1305_internal;
static void poly1305_init(void *ctx, const unsigned char key[16])
{
    poly1305_internal *st = (poly1305_internal *) ctx;
    st->h[0] = 0;
    st->h[1] = 0;
    st->h[2] = 0;
    st->h[3] = 0;
    st->h[4] = 0;
    st->r[0] = U8TOU32(&key[0]) & 0x0fffffff;
    st->r[1] = U8TOU32(&key[4]) & 0x0ffffffc;
    st->r[2] = U8TOU32(&key[8]) & 0x0ffffffc;
    st->r[3] = U8TOU32(&key[12]) & 0x0ffffffc;
}
void Poly1305_Init(POLY1305 *ctx, const unsigned char key[32])
{
    ctx->nonce[0] = U8TOU32(&key[16]);
    ctx->nonce[1] = U8TOU32(&key[20]);
    ctx->nonce[2] = U8TOU32(&key[24]);
    ctx->nonce[3] = U8TOU32(&key[28]);
    poly1305_init(ctx->opaque, key);
    ctx->num = 0;
}
