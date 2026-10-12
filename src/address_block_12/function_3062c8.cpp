struct source {
    char reserved0[0x148];
    int field_148;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_3062c8(source* object, void*, value_slot* slot) {
    int value = object->field_148;
    slot->type = 1;
    slot->value = value;
    return 1;
}
