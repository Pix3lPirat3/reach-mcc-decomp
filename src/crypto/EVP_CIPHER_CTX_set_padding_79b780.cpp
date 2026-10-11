struct evp_cipher_ctx {
    unsigned char reserved0[108];
    int flags;
};

extern "C" int EVP_CIPHER_CTX_set_padding_79b780(evp_cipher_ctx* ctx, int padding) {
    int flags = ctx->flags;
    ctx->flags = padding == 0 ? flags | 0x100 : flags & -257;
    return 1;
}
