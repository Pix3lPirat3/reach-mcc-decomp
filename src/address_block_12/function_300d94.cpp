struct source {
    char reserved0[0x80];
    int field_80;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_300d94(source* object, void*, value_slot* slot) {
    slot->value = object->field_80;
    slot->type = 6;
    return 1;
}
