struct source {
    char reserved0[0x9b4];
    int field_9b4;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_304ca0(source* object, void*, value_slot* slot) {
    int value = object->field_9b4;
    slot->type = 1;
    slot->value = value;
    return 1;
}
