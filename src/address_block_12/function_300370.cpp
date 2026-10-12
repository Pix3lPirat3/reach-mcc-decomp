struct source {
    char reserved0[0x170];
    int field_170;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_300370(source* object, void*, value_slot* slot) {
    slot->value = object->field_170;
    slot->type = 6;
    return 1;
}
