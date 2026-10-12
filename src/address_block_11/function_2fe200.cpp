struct source {
    char reserved0[0x148];
    long long field_148;
};

struct value_slot {
    int type;
    int reserved4;
    long long value;
};

extern "C" char function_2fe200(source* object, void*, value_slot* slot) {
    slot->value = object->field_148;
    slot->type = 4;
    return 1;
}
