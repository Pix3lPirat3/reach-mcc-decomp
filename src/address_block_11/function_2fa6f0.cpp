struct object_state {
    unsigned char reserved0[0x130];
    int field_130;
};

struct value_out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2fa6f0(object_state* object, void*, value_out* out) {
    out->value = object->field_130;
    out->kind = 6;
    return 1;
}
