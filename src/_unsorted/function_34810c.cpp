struct object_a {
    unsigned char reserved0[0x7a];
    bool field_7a;
};

struct object_c {
    unsigned int field_0;
    unsigned char reserved4[4];
    bool field_8;
};
extern "C" bool function_34810c(object_a* object, long long, object_c* input) {
    bool loaded = object->field_7a;
    input->field_0 = 0;
    input->field_8 = loaded;
    return true;
}
