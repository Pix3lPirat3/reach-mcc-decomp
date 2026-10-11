struct engine {
    unsigned char reserved0[0x70];
    void* ctrl_function;
};

extern "C" int ENGINE_set_ctrl_function_7d1f50(engine* target, void* value) {
    target->ctrl_function = value;
    return 1;
}
