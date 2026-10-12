struct value_slot {
    int type;
    int reserved4;
    char* value;
};

extern "C" char function_3039c8(char* object, void*, value_slot* slot) {
    slot->type = 3;
    slot->value = object + 0x9b4;
    return 1;
}
