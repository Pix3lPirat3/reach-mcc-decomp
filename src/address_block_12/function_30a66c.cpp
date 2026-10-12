struct slot_value {
    int type;
    int reserved4;
    int value;
};

extern "C" char function_30a66c(char* object, void*, slot_value* slot) {
    long long value = 0;
    char* first;
    if (object[0xec0] == 0 || object[0xc8] == 0)
        first = nullptr;
    else
        first = object + 0xc9;
    char* second;
    if (first == nullptr) {
no_second:
        second = nullptr;
    } else {
        second = first + 0x1db;
        if (*second == 0)
            goto no_second;
    }
    if (second != nullptr)
        value = *(int*)(second + 0xa51);
    slot->value = (int)value;
    slot->type = 1;
    return 1;
}
