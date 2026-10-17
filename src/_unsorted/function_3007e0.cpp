struct source {
    char reserved0[0x178];
    int field_178;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_3007e0(source* object, void*, value_slot* slot) {
    slot->value = object->field_178;
    slot->type = 6;
    return 1;
}
