struct rsa_method_state {
    unsigned char reserved0[0x74];
    unsigned int flags;
};

extern "C" long long rsa_ossl_init_7c8880(rsa_method_state* state) {
    state->flags |= 6;
    return 1;
}
