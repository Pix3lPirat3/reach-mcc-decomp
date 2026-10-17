struct object_state {
    unsigned char reserved0[0x170];
    int field_170;
    int field_174;
};

struct value_in {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2f93ec(object_state* object, void*, value_in* in) {
    int value = in->value;
    object->field_174 = 0;
    object->field_170 = value;
    return 1;
}
