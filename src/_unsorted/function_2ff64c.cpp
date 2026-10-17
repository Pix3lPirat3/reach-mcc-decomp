struct source {
    char reserved0[0x13120];
    int field_13120;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_2ff64c(source* object, void*, value_slot* slot) {
    int value = object->field_13120;
    slot->type = 1;
    slot->value = value;
    return 1;
}
