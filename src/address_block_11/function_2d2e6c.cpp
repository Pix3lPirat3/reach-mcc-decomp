struct object_state {
    unsigned char reserved0[0x170];
    long long field_170;
};

struct value_out {
    int kind;
    int reserved4;
    long long value;
};

extern "C" char function_2d2e6c(object_state* object, void*, value_out* out) {
    out->value = object->field_170;
    out->kind = 4;
    return 1;
}
