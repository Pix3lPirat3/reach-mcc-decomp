struct object_state {
    unsigned char reserved0[0x38c];
    int field_38c;
};

struct value_out {
    int kind;
    int reserved4;
    int value;
};

extern "C" char function_2f8b3c(object_state* object, void*, value_out* out) {
    int value = object->field_38c;
    out->kind = 1;
    out->value = value;
    return 1;
}
