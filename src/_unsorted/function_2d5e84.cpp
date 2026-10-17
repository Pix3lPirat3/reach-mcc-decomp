struct object_state {
    unsigned char reserved0[0x9c];
    int field_9c;
    int field_a0;
};

struct value_in {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2d5e84(object_state* object, void*, value_in* in) {
    int value = in->value;
    object->field_a0 = 0;
    object->field_9c = value;
    return 1;
}
