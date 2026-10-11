struct engine {
    unsigned char reserved0[0x68];
    void* finish_function;
};

extern "C" int ENGINE_set_finish_function_7d1f90(engine* target, void* value) {
    target->finish_function = value;
    return 1;
}
