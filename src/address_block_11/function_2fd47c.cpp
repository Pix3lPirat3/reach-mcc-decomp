struct source {
    char reserved0[0x70];
    char* field_70;
};

struct value_slot {
    int reserved0;
    int reserved4;
    char* value;
};

extern "C" long long function_2fd1a0(source* object);

extern "C" char function_2fd47c(source* object, void*, value_slot* slot) {
    object->field_70 = slot->value;
    function_2fd1a0(object);
    return 1;
}
