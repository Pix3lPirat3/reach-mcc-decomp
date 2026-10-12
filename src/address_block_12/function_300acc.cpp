struct source {
    char reserved0[0xac];
    char field_ac;
};

struct value_slot {
    int type;
    int reserved4;
    char value;
};

extern "C" char function_300acc(source* object, void*, value_slot* slot) {
    char value = object->field_ac;
    slot->type = 0;
    slot->value = value;
    return 1;
}
