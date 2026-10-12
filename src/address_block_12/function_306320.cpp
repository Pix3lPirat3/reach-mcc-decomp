struct source {
    char reserved0[0x150];
    int field_150;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_306320(source* object, void*, value_slot* slot) {
    int value = object->field_150;
    slot->type = 1;
    slot->value = value;
    return 1;
}
