struct object_state {
    unsigned char reserved0[0x390];
    int field_390;
};

struct value_out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2f8b60(object_state* object, void*, value_out* out) {
    int value = object->field_390;
    out->kind = 1;
    out->value = value;
    return 1;
}
