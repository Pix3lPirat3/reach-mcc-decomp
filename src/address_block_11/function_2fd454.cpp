struct value_slot {
    int type;
    int reserved4;
    char* value;
};

extern "C" char function_2fd454(char* object, void*, value_slot* slot) {
    slot->type = 3;
    slot->value = object + 0x7c;
    return 1;
}
