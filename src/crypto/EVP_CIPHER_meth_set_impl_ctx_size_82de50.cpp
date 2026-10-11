struct method {
    unsigned char reserved0[0x30];
    int impl_ctx_size;
};

extern "C" int EVP_CIPHER_meth_set_impl_ctx_size_82de50(method* target, int value) {
    target->impl_ctx_size = value;
    return 1;
}
