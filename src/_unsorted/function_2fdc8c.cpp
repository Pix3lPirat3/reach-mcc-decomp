struct source {
    char reserved0[0x138];
    long long field_138;
};

struct value_slot {
    int type;
    int reserved4;
    long long value;
};

extern "C" char function_2fdc8c(source* object, void*, value_slot* slot) {
    slot->value = object->field_138;
    slot->type = 3;
    return 1;
}
