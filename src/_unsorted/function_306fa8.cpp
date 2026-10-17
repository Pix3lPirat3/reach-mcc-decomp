struct value_slot {
    int type;
    int reserved4;
    char* value;
};

extern "C" char function_306fa8(char* object, void*, value_slot* slot) {
    slot->type = 9;
    slot->value = object + 0x98;
    return 1;
}
