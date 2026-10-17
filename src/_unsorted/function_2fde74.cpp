struct source {
    char reserved0[0x178];
    int field_178;
    int field_17c;
};

struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_2fde74(source* object, void*, value_slot* slot) {
    int value = slot->value;
    object->field_17c = 0;
    object->field_178 = value;
    return 1;
}
