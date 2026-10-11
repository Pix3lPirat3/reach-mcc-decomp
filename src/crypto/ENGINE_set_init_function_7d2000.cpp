struct engine {
    unsigned char reserved0[0x60];
    void* init_function;
};

extern "C" int ENGINE_set_init_function_7d2000(engine* target, void* value) {
    target->init_function = value;
    return 1;
}
