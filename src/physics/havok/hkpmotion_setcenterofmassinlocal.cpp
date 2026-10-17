struct motion {
    unsigned char reserved0[0x20];
    unsigned char state[1];
};

extern "C" void function_903fb0(void* value, void* state);

extern "C" void function_8b2120(motion* body, void* value) {
    return function_903fb0(value, body->state);
}
