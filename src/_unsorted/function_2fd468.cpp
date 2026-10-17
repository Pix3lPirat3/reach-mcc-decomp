struct source {
    char reserved0[0x70];
    long long field_70;
};

struct value_slot {
    int type;
    int reserved4;
    long long value;
};

extern "C" char function_2fd468(source* object, void*, value_slot* slot) {
    slot->value = object->field_70;
    slot->type = 8;
    return 1;
}
