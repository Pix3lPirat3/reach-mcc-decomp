struct target_object {
    unsigned char reserved0[0x148];
    int value;
    int scale;
};

struct input_slot {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_38a54c(target_object* target, void*, input_slot* input) {
    target->value = input->value;
    target->scale = 0x3F800000;
    return 1;
}
