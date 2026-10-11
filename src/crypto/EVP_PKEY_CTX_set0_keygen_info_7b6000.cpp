struct pkey_context {
    unsigned char reserved0[0x40];
    void* keygen_info;
    int keygen_count;
};

extern "C" void EVP_PKEY_CTX_set0_keygen_info_7b6000(pkey_context* context, void* info, int count) {
    context->keygen_info = info;
    context->keygen_count = count;
}
