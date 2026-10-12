struct source {
    char reserved0[0x1208];
    int field_1208;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_304d24(source* object, void*, value_slot* slot) {
    int value = object->field_1208;
    slot->type = 1;
    slot->value = value;
    return 1;
}
