struct object_a {
    unsigned char reserved0[0x7b];
    bool field_7b;
};

struct object_c {
    unsigned int field_0;
    unsigned char reserved4[4];
    bool field_8;
};
extern "C" bool function_34811c(object_a* object, long long, object_c* input) {
    bool loaded = object->field_7b;
    input->field_0 = 0;
    input->field_8 = loaded;
    return true;
}
