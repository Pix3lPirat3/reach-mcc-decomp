struct object_a {
    unsigned char reserved0[0x7c];
    bool field_7c;
};

struct object_c {
    unsigned int field_0;
    unsigned char reserved4[4];
    bool field_8;
};
extern "C" bool function_3538b8(object_a* object, long long, object_c* input) {
    bool loaded = object->field_7c;
    input->field_0 = 0;
    input->field_8 = loaded;
    return true;
}
