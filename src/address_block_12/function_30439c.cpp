struct value_slot {
    int type;
    int reserved4;
    int value;
};

extern "C" int function_3041ac(void* object);

extern "C" char function_30439c(void* object, void*, value_slot* slot) {
    slot->value = function_3041ac(object);
    slot->type = 1;
    return 1;
}
