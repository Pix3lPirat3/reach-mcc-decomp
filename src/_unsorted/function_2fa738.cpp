struct object_state {
    unsigned char reserved0[0x138];
    unsigned char field_138;
};

struct pointer_out {
    int kind;
    int reserved4;
    void* value;
};

extern "C" char function_2fa738(object_state* object, void*, pointer_out* out) {
    out->kind = 9;
    out->value = &object->field_138;
    return 1;
}
