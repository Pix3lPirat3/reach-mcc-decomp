struct list_state {
    unsigned char reserved0[0x20];
    long long field_20;
};

extern "C" long long function_176808(list_state* list);

extern "C" long long function_176840(list_state* list) {
    long long result = function_176808(list);
    list->field_20 = 0;
    return result;
}
