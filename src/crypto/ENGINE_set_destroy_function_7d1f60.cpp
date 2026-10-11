struct engine {
    unsigned char reserved0[0x58];
    void* destroy_function;
};

extern "C" int ENGINE_set_destroy_function_7d1f60(engine* target, void* value) {
    target->destroy_function = value;
    return 1;
}
