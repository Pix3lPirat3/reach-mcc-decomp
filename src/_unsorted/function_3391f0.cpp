struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" int function_2a3838(void* object, void* extra);

extern "C" char function_3391f0(void* object, void* extra, value_slot* out) {
    out->number = function_2a3838(object, extra);
    out->kind = 1;
    return 1;
}
