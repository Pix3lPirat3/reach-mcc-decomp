struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x2b0];
    unsigned int field_2b0;
};
extern "C" bool function_3430c8(object_a* object, long long, object_c* input) {
    object->field_2b0 = input->field_8;
    return true;
}
