struct slot_value {
    int type;
    int reserved4;
    char value;
};

extern "C" char function_307af0(char* object, void*, slot_value* slot) {
    char* first;
    if (object[0xec0] == 0) {
no_first:
        first = nullptr;
    } else {
        first = object + 0xc9;
        if (object[0xc8] == 0)
            goto no_first;
    }
    char* second;
    if (first == nullptr) {
no_second:
        second = nullptr;
    } else {
        second = first + 0x5;
        if (*second == 0)
            goto no_second;
    }
    slot->type = 0;
    slot->value = second != nullptr;
    return 1;
}
