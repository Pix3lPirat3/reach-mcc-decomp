struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" char function_336e4c(char* object, void*, value_slot* slot) {
    *reinterpret_cast<int*>(object + 0x88) = slot->number;
    *(object + 0x8c) = 1;
    return 1;
}
