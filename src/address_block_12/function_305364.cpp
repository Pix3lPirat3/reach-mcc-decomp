struct source {
    char reserved0[0x9c];
    int field_9c;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_305364(source* object, void*, value_slot* slot) {
    int value = object->field_9c;
    slot->type = 1;
    slot->value = value;
    return 1;
}
