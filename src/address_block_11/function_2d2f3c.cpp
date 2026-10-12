struct object_a {
    unsigned char reserved0[0x72];
    unsigned char field_72;
};

struct object_c {
    unsigned int field_0;
    unsigned char reserved4[4];
    unsigned char field_8;
};
extern "C" bool function_2d2f3c(object_a* object, long long, object_c* input) {
    unsigned char loaded = object->field_72;
    input->field_0 = 0;
    input->field_8 = loaded & 1;
    return true;
}
