struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" long long function_332fd0(char* object);

extern "C" char function_333348(char* object, void*, value_slot* out) {
    out->number = (int)function_332fd0(object);
    out->kind = 1;
    return 1;
}
