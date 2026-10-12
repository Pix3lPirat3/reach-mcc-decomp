struct object_state {
    unsigned char reserved0[0xc0];
    long long field_c0;
};

struct value_out {
    int kind;
    int reserved4;
    long long value;
};

extern "C" char function_2d5fac(object_state* object, void*, value_out* out) {
    out->value = object->field_c0;
    out->kind = 4;
    return 1;
}
