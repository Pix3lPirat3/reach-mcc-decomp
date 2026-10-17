struct object_state {
    unsigned char reserved0[0xb4];
    int field_b4;
    int field_b8;
};

struct value_in {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2d5f50(object_state* object, void*, value_in* in) {
    int value = in->value;
    object->field_b8 = 0;
    object->field_b4 = value;
    return 1;
}
