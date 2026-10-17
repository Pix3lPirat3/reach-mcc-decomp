struct source {
    char reserved0[0x19b4];
    int field_19b4;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_3039f8(source* object, void*, value_slot* slot) {
    int value = object->field_19b4;
    slot->type = 1;
    slot->value = value;
    return 1;
}
