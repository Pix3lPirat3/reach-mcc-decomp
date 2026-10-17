struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" char function_38e888(int count);

extern "C" char function_338014(char*, void*, value_slot* slot) {
    int count = slot->number;
    if ((unsigned int)(count - 1) > 15)
        return 1;
    function_38e888(count);
    return 1;
}
