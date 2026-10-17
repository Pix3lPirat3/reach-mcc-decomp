struct object_state {
    unsigned char reserved0[0xa0];
    int field_a0;
};

struct value_out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2fbd80(object_state* object, void*, value_out* out) {
    int value = object->field_a0;
    out->kind = 1;
    out->value = value;
    return 1;
}
