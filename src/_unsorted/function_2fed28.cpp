struct source {
    char reserved0[0x98];
    int field_98;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_2fed28(source* object, void*, value_slot* slot) {
    int value = object->field_98;
    slot->type = 1;
    slot->value = value;
    return 1;
}
