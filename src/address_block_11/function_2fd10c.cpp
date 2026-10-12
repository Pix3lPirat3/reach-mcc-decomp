struct object_state {
    unsigned char reserved0[0x80];
    long long field_80;
};

struct value_out {
    int kind;
    int reserved4;
    long long value;
};

extern "C" char function_2fd10c(object_state* object, void*, value_out* out) {
    out->value = object->field_80;
    out->kind = 4;
    return 1;
}
