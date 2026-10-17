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

extern "C" char function_306304(source* object, void*, value_slot* slot) {
    bool before_last = object->field_158 < object->count - 1;
    slot->type = 0;
    slot->value = before_last;
    return 1;
}
