struct source {
    char reserved0[0x154];
    int field_154;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_2fdd48(source* object, void*, value_slot* slot) {
    slot->value = object->field_154;
    slot->type = 6;
    return 1;
}
