struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0xa8];
    unsigned int field_a8;
};
extern "C" bool function_300abc(object_a* object, long long, object_c* input) {
    object->field_a8 = input->field_8;
    return true;
}
