struct object_state {
    unsigned char reserved0[0x70];
    unsigned int flags;
};

struct flag_in {
    int kind;
    int reserved4;
    char flag;
};

extern "C" char function_2d3268(object_state* object, void*, flag_in* in) {
    unsigned int flags = object->flags;
    unsigned int mask = 0x8000000u;
    object->flags = in->flag == 0 ? flags & ~mask : flags | mask;
    return 1;
}
