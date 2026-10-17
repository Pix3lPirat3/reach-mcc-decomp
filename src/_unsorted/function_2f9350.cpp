struct object_state {
    unsigned char reserved0[0x158];
    int field_158;
    int field_15c;
};

struct value_in {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2f9350(object_state* object, void*, value_in* in) {
    int value = in->value;
    object->field_15c = 0;
    object->field_158 = value;
    return 1;
}
