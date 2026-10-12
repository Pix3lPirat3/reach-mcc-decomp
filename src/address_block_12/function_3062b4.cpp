struct source {
    char reserved0[0x70];
    unsigned int flags;
};

struct value_slot {
    int type;
    int reserved4;
    char value;
};

extern "C" char function_3062b4(source* object, void*, value_slot* slot) {
    unsigned int flags = object->flags;
    slot->type = 0;
    slot->value = (char)((flags >> 12) & 1);
    return 1;
}
