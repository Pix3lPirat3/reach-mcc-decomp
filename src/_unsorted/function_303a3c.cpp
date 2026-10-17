struct value_slot {
    int type;
    int reserved4;
    char* value;
};

extern "C" char function_303a3c(char* object, void*, value_slot* slot) {
    slot->type = 3;
    slot->value = object + 0x29b8;
    return 1;
}
