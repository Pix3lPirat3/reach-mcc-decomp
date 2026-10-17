struct object_state {
    unsigned char reserved0[0x70];
    unsigned int flags;
};

struct flag_out {
    int kind;
    int reserved4;
    char flag;
};

extern "C" char function_2d2fb4(object_state* object, void*, flag_out* out) {
    char result = 1;
    unsigned int flags = object->flags;
    out->kind = 0;
    out->flag = (char)(flags >> 15) & result;
    return result;
}
