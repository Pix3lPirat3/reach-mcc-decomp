struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0xb0];
    unsigned int field_b0;
};
extern "C" bool function_300b04(object_a* object, long long, object_c* input) {
    object->field_b0 = input->field_8;
    return true;
}
