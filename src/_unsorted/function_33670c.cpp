struct value_slot {
    int kind;
    int reserved4;
    float number;
};

extern "C" long long c_number_formatter_component__format_number_336438(char* object, float number, value_slot* slot, long long extra);

extern "C" char function_33670c(char* object, void*, value_slot* slot, long long extra) {
    c_number_formatter_component__format_number_336438(object, slot->number, slot, extra);
    return 1;
}
