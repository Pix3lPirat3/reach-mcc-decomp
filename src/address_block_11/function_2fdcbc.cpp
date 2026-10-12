struct source {
    char reserved0[0x140];
    long long field_140;
};

struct value_slot {
    int type;
    int reserved4;
    long long value;
};

extern "C" char function_2fdcbc(source* object, void*, value_slot* slot) {
    slot->value = object->field_140;
    slot->type = 12;
    return 1;
}
