struct object_state {
    unsigned char reserved0[0x168];
    int field_168;
    int field_16c;
};

struct value_in {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2f93b8(object_state* object, void*, value_in* in) {
    int value = in->value;
    object->field_16c = 0;
    object->field_168 = value;
    return 1;
}
