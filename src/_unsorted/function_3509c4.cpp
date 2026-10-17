struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x2a4];
    unsigned int field_2a4;
};
extern "C" bool function_3509c4(object_a* object, long long, object_c* input) {
    object->field_2a4 = input->field_8;
    return true;
}
