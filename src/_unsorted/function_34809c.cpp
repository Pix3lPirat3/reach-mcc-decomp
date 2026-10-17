struct object_a {
    unsigned char reserved0[0x79];
    bool field_79;
};

struct object_c {
    unsigned int field_0;
    unsigned char reserved4[4];
    bool field_8;
};
extern "C" bool function_34809c(object_a* object, long long, object_c* input) {
    bool loaded = object->field_79;
    input->field_0 = 0;
    input->field_8 = loaded;
    return true;
}
