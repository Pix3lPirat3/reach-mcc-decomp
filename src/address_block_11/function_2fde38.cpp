struct source {
    char reserved0[0x70];
    unsigned int flags;
};

struct value_slot {
    int type;
    int reserved4;
    char value;
};

extern "C" char function_2fde38(source* object, void*, value_slot* slot) {
    int flags = (int)object->flags;
    object->flags = (unsigned int)(slot->value == 0 ? flags & ~0x800 : flags | 0x800);
    return 1;
}
