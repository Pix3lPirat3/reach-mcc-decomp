struct source {
    char reserved0[0x174];
    int field_174;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_300394(source* object, void*, value_slot* slot) {
    slot->value = object->field_174;
    slot->type = 6;
    return 1;
}
