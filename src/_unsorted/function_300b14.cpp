struct source {
    char reserved0[0xb8];
    long long field_b8;
};

struct value_slot {
    int type;
    int reserved4;
    long long value;
};

extern "C" char function_300b14(source* object, void*, value_slot* slot) {
    slot->value = object->field_b8;
    slot->type = 4;
    return 1;
}
