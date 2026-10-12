struct source {
    char reserved0[0x70];
    int field_70;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_2fe67c(source* object, void*, value_slot* slot) {
    int value = object->field_70;
    slot->type = 1;
    slot->value = value;
    return 1;
}
