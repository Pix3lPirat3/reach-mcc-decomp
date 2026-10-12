struct object_state {
    unsigned char reserved0[0x134];
    int field_134;
};

struct value_out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2fa714(object_state* object, void*, value_out* out) {
    out->value = object->field_134;
    out->kind = 6;
    return 1;
}
