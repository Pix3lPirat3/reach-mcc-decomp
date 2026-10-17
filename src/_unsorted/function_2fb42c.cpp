struct object_state {
    unsigned char reserved0[0x98];
    long long field_98;
};

struct value_out {
    int kind;
    int reserved4;
    long long value;
};

extern "C" char function_2fb42c(object_state* object, void*, value_out* out) {
    out->value = object->field_98;
    out->kind = 4;
    return 1;
}
