struct object_a {
    unsigned char reserved0[0x71];
    bool field_71;
};

struct object_c {
    unsigned int field_0;
    unsigned char reserved4[4];
    bool field_8;
};
extern "C" bool function_33f250(object_a* object, long long, object_c* input) {
    bool loaded = object->field_71;
    input->field_0 = 0;
    input->field_8 = loaded;
    return true;
}
