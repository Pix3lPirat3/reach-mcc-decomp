struct object_state {
    unsigned char reserved0[0x84];
    char field_84;
};

struct byte_out {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_2f4918(object_state* object, void*, byte_out* out) {
    char value = object->field_84;
    out->kind = 0;
    out->value = value;
    return 1;
}
