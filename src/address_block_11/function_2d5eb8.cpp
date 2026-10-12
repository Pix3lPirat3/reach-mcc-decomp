struct object_state {
    unsigned char reserved0[0xa4];
    int field_a4;
    int field_a8;
};

struct value_in {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2d5eb8(object_state* object, void*, value_in* in) {
    int value = in->value;
    object->field_a8 = 0;
    object->field_a4 = value;
    return 1;
}
