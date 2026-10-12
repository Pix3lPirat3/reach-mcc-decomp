struct object_state {
    unsigned char reserved0[0x1bc];
    int field_1bc;
};

struct value_out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2d2f68(object_state* object, void*, value_out* out) {
    out->value = object->field_1bc;
    out->kind = 6;
    return 1;
}
