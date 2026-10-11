struct engine {
    unsigned char reserved0[0x30];
    void* rand_method;
};

extern "C" int ENGINE_set_RAND_7d1160(engine* target, void* value) {
    target->rand_method = value;
    return 1;
}
