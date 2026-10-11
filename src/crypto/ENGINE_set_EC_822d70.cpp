struct engine {
    unsigned char reserved0[0x28];
    void* ec_method;
};

extern "C" int ENGINE_set_EC_822d70(engine* target, void* value) {
    target->ec_method = value;
    return 1;
}
