struct source {
    char reserved0[0x188];
    int field_188;
    int field_18c;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_2fdedc(source* object, void*, value_slot* slot) {
    object->field_188 = slot->value;
    object->field_18c = 0x3f800000;
    return 1;
}
