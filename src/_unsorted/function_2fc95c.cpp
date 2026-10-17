struct object_state {
    unsigned char reserved0[0x80];
    unsigned char field_80;
    unsigned char reserved81[0xf0 - 0x81];
    int field_f0;
};

struct pointer_out {
    int kind;
    int reserved4;
    void* value;
};

extern "C" char function_2fc95c(object_state* object, void*, pointer_out* out) {
    int index = object->field_f0;
    out->kind = 4;
    out->value = index != -1 ? &object->field_80 : nullptr;
    return 1;
}
