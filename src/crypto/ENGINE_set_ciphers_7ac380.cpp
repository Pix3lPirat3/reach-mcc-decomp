struct engine {
    unsigned char reserved0[0x38];
    void* ciphers;
};

extern "C" int ENGINE_set_ciphers_7ac380(engine* target, void* value) {
    target->ciphers = value;
    return 1;
}
