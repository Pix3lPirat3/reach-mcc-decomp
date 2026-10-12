struct value_slot {
    int type;
    int reserved4;
    char value;
};

extern "C" char function_307a80(char* object, void*, value_slot* slot) {
    char* first;
    if (object[0xec0] == 0 || object[0xc8] == 0)
        first = nullptr;
    else
        first = object + 0xc9;
    slot->type = 0;
    slot->value = first != nullptr;
    return 1;
}
