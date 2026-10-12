struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x230];
    unsigned int field_230;
};
extern "C" bool function_306afc(object_a* object, long long, object_c* input) {
    object->field_230 = input->field_8;
    return true;
}
