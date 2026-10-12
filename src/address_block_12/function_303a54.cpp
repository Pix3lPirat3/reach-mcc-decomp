struct value_slot {
    int type;
    int reserved4;
    char* value;
};

extern "C" char function_303a54(char* object, void*, value_slot* slot) {
    slot->type = 3;
    slot->value = object + 0x2ab8;
    return 1;
}
