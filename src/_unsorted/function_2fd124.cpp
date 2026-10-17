struct object_state {
    unsigned char reserved0[0x70];
    long long field_70;
};

struct value_out {
    int kind;
    int reserved4;
    long long value;
};

extern "C" char function_2fd124(object_state* object, void*, value_out* out) {
    out->value = object->field_70;
    out->kind = 4;
    return 1;
}
