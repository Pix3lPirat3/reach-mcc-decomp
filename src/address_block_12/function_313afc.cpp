struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0xc0];
    unsigned int field_c0;
};
extern "C" bool function_313afc(object_a* object, long long, object_c* input) {
    object->field_c0 = input->field_8;
    return true;
}
