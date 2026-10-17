struct source {
    char reserved0[0x70];
    int flags;
};

struct value_slot {
    int type;
    int reserved4;
    char value;
};

extern "C" void* function_3053ec(source* object);

extern "C" char function_305578(source* object, void*, value_slot* slot) {
    int flags = object->flags;
    object->flags = slot->value == 0 ? flags & ~0x800 : flags | 0x800;
    function_3053ec(object);
    return 1;
}
