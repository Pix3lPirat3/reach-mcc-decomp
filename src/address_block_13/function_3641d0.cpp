struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x2d09];
    bool field_2d09;
};
extern "C" bool function_3641d0(object_a* object, long long, object_c* input) {
    object->field_2d09 = input->field_8;
    return true;
}
