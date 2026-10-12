struct target_object {
    unsigned char reserved0[0x80];
    unsigned int value;
};

struct input_slot {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_3805a4(target_object* target, void*, input_slot* input) {
    target->value = input->value >= 0 ? *(unsigned int*)&input->value : 0;
    return 1;
}
