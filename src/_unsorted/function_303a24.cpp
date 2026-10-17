struct value_slot {
    int type;
    int reserved4;
    char* value;
};

extern "C" char function_303a24(char* object, void*, value_slot* slot) {
    slot->type = 3;
    slot->value = object + 0x21b8;
    return 1;
}
