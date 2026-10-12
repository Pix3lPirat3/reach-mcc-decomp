struct object_state {
    unsigned char reserved0[0x88];
    long long field_88;
    unsigned char reserved90[0x1080 - 0x90];
    int field_1080;
};

struct flag_out {
    int kind;
    int reserved4;
    char flag;
};

extern "C" char function_2f9c34(object_state* object, void*, flag_out* out) {
    char flag;
    if (object->field_88 != 0 || object->field_1080 != -1)
        flag = 1;
    else
        flag = 0;
    out->kind = 0;
    out->flag = flag;
    return 1;
}
