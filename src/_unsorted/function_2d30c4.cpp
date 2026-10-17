struct object_state {
    unsigned char reserved0[0x1c8];
    int field_1c8;
    int field_1cc;
};

struct value_in {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2d30c4(object_state* object, void*, value_in* in) {
    int value = in->value;
    object->field_1cc = 0;
    object->field_1c8 = value;
    return 1;
}
