struct value_slot {
    int type;
    int reserved4;
    char* value;
};

extern "C" char function_304d0c(char* object, void*, value_slot* slot) {
    slot->type = 3;
    slot->value = object + 0xa08;
    return 1;
}
