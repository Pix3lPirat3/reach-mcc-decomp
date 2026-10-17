struct object_a {
    unsigned char reserved0[0x70];
    unsigned char field_70;
};

struct object_c {
    unsigned int field_0;
    unsigned char reserved4[4];
    unsigned char field_8;
};
extern "C" bool function_2d5d9c(object_a* object, long long, object_c* input) {
    unsigned char loaded = object->field_70;
    input->field_0 = 0;
    input->field_8 = loaded & 1;
    return true;
}
