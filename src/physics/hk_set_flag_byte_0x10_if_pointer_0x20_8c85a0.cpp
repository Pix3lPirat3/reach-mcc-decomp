struct flag_object {
    unsigned char reserved0[0x10];
    unsigned char flag;
};

struct pointer_object {
    unsigned char reserved0[0x20];
    void* pointer;
};

extern "C" void hk_set_flag_byte_0x10_if_pointer_0x20_8c85a0(flag_object* target, pointer_object* source) {
    if (source->pointer == 0)
        return;
    target->flag = 1;
}
