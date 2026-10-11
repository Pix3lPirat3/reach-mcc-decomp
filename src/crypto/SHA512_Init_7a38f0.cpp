struct sha512_ctx {
    unsigned long long h0;
    unsigned long long h1;
    unsigned long long h2;
    unsigned long long h3;
    unsigned long long h4;
    unsigned long long h5;
    unsigned long long h6;
    unsigned long long h7;
    unsigned long long length_low;
    unsigned long long length_high;
    unsigned char data[0x80];
    unsigned int num;
    unsigned int md_len;
};

extern "C" long long SHA512_Init_7a38f0(sha512_ctx* ctx) {
    ctx->md_len = 0x40;
    ctx->h0 = 0x6A09E667F3BCC908;
    ctx->h1 = 0xBB67AE8584CAA73B;
    ctx->h2 = 0x3C6EF372FE94F82B;
    ctx->h3 = 0xA54FF53A5F1D36F1;
    ctx->h4 = 0x510E527FADE682D1;
    ctx->h5 = 0x9B05688C2B3E6C1F;
    ctx->h6 = 0x1F83D9ABFB41BD6B;
    ctx->h7 = 0x5BE0CD19137E2179;
    ctx->length_low = 0;
    ctx->length_high = 0;
    ctx->num = 0;
    return 1;
}
