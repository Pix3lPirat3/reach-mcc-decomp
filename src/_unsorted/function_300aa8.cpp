struct source {
    char reserved0[0xa8];
    int field_a8;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_300aa8(source* object, void*, value_slot* slot) {
    slot->value = object->field_a8;
    slot->type = 6;
    return 1;
}
