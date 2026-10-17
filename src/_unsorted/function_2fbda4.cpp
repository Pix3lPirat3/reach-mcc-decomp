struct object_state {
    unsigned char reserved0[0xa8];
    long long field_a8;
};

struct value_out {
    int kind;
    int reserved4;
    long long value;
};

extern "C" char function_2fbda4(object_state* object, void*, value_out* out) {
    out->value = object->field_a8;
    out->kind = 4;
    return 1;
}
