struct object_state {
    unsigned char reserved0[0x70];
    int field_70;
};

struct value_out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2f8b1c(object_state* object, void*, value_out* out) {
    out->value = object->field_70;
    out->kind = 6;
    return 1;
}
