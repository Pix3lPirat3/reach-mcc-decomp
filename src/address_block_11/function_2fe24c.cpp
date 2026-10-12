struct source {
    char reserved0[0x150];
    long long field_150;
};

struct value_slot {
    int type;
    int reserved4;
    long long value;
};

extern "C" char function_2fe24c(source* object, void*, value_slot* slot) {
    slot->value = object->field_150;
    slot->type = 4;
    return 1;
}
