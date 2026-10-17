struct source {
    char reserved0[0xb0];
    int field_b0;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_300af0(source* object, void*, value_slot* slot) {
    slot->value = object->field_b0;
    slot->type = 6;
    return 1;
}
