struct value_slot {
    int kind;
    int reserved4;
    char flag;
};

extern "C" long long function_33b930(char* object);

extern "C" char function_33bb18(char* object, void*, value_slot* out) {
    long long result = function_33b930(object);
    out->kind = 0;
    out->flag = (char)result;
    return 1;
}
