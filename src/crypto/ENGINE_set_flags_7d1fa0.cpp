struct engine {
    unsigned char reserved0[0x98];
    int flags;
};

extern "C" int ENGINE_set_flags_7d1fa0(engine* target, int flags) {
    target->flags = flags;
    return 1;
}
