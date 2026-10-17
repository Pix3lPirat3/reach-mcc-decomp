struct source {
    char reserved0[0x978];
    int field_978;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_2ff024(source* object, void*, value_slot* slot) {
    int value = object->field_978;
    slot->type = 1;
    slot->value = value;
    return 1;
}
