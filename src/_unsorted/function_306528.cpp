struct source {
    char reserved0[0x148];
    int field_148;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_306528(source* object, void*, value_slot* slot) {
    slot->value = object->field_148;
    slot->type = 6;
    return 1;
}
