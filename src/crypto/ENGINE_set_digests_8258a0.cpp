struct engine {
    unsigned char reserved0[0x40];
    void* digests;
};

extern "C" int ENGINE_set_digests_8258a0(engine* target, void* value) {
    target->digests = value;
    return 1;
}
