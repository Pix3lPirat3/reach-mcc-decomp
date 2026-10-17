struct object_state {
    unsigned char reserved0[0x160];
    int field_160;
    int field_164;
};

struct value_in {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2f9384(object_state* object, void*, value_in* in) {
    int value = in->value;
    object->field_164 = 0;
    object->field_160 = value;
    return 1;
}
