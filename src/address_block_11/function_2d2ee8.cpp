struct object_state {
    unsigned char reserved0[0x164];
    int field_164;
};

struct value_out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2d2ee8(object_state* object, void*, value_out* out) {
    out->value = object->field_164;
    out->kind = 6;
    return 1;
}
