struct source {
    char reserved0[0x148];
    int count;
    int reserved14c;
    int field_150;
    int reserved154;
    int field_158;
};

struct value_slot {
    int type;
    int reserved4;
    char value;
};

extern "C" char function_3062ec(source* object, void*, value_slot* slot) {
    bool positive = object->field_158 > 0;
    slot->type = 0;
    slot->value = positive;
    return 1;
}
