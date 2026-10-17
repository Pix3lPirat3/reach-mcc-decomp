struct source {
    char reserved0[0x180];
    int field_180;
    int field_184;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_2fdea8(source* object, void*, value_slot* slot) {
    int value = slot->value;
    object->field_184 = 0;
    object->field_180 = value;
    return 1;
}
