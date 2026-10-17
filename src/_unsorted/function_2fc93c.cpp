struct object_state {
    unsigned char reserved0[0x78];
    int field_78;
};

struct value_out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2fc93c(object_state* object, void*, value_out* out) {
    out->value = object->field_78;
    out->kind = 6;
    return 1;
}
