struct object_state {
    unsigned char reserved0[0x94];
    int field_94;
    float field_98;
};

struct value_in {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2d5e1c(object_state* object, void*, value_in* in) {
    object->field_94 = in->value;
    object->field_98 = 1.0f;
    return 1;
}
