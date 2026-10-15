struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" int function_2a37fc(void* object, void* extra);

extern "C" char function_3391d0(void* object, void* extra, value_slot* out) {
    out->number = function_2a37fc(object, extra);
    out->kind = 1;
    return 1;
}
