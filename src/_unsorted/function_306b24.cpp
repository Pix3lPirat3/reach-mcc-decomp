struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x234];
    unsigned int field_234;
};
extern "C" bool function_306b24(object_a* object, long long, object_c* input) {
    object->field_234 = input->field_8;
    return true;
}
