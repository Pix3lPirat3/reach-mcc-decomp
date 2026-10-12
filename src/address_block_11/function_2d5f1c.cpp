struct object_state {
    unsigned char reserved0[0xac];
    int field_ac;
    int field_b0;
};

struct value_in {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2d5f1c(object_state* object, void*, value_in* in) {
    int value = in->value;
    object->field_b0 = 0;
    object->field_ac = value;
    return 1;
}
