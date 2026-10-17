struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0xa0];
    unsigned int field_a0;
};
extern "C" bool function_2fbd94(object_a* object, long long, object_c* input) {
    object->field_a0 = input->field_8;
    return true;
}
