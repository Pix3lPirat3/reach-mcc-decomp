struct source {
    char reserved0[0x180];
    long long field_180;
};

struct value_slot {
    int type;
    int reserved4;
    long long value;
};

extern "C" char function_3063b8(source* object, void*, value_slot* slot) {
    slot->value = object->field_180;
    slot->type = 4;
    return 1;
}
