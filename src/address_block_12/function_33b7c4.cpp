struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" char function_33b7c4(char* object, void*, value_slot* out) {
    int value = *reinterpret_cast<int*>(object + 0x19724);
    out->kind = 1;
    out->number = value;
    return 1;
}
