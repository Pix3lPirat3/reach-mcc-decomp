struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0xfac];
    unsigned int field_fac;
};
extern "C" bool function_344904(object_a* object, long long, object_c* input) {
    object->field_fac = input->field_8;
    return true;
}
