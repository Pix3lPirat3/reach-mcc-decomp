struct method {
    unsigned char reserved0[0x10];
    int flags;
};

extern "C" int EVP_CIPHER_meth_set_flags_82de40(method* target, int value) {
    target->flags = value;
    return 1;
}
