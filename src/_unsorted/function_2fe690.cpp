struct source {
    char reserved0[0x74];
    int field_74;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_2fe690(source* object, void*, value_slot* slot) {
    int value = object->field_74;
    slot->type = 1;
    slot->value = value;
    return 1;
}
