struct object_state {
    unsigned char reserved0[0x8c];
    char field_8c;
};

struct byte_out {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_2fd0c0(object_state* object, void*, byte_out* out) {
    char value = object->field_8c;
    out->kind = 0;
    out->value = value;
    return 1;
}
