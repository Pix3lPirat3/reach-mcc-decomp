struct target_object {
    unsigned char reserved0[0x158];
    int value;
};

struct input_slot {
    int kind;
    int reserved4;
    int value;
};

extern "C" long long function_38680c(target_object* target, void*, input_slot* input) {
    int value = input->value;
    target->value = value < 1 ? 1 : value;
    return 1;
}
