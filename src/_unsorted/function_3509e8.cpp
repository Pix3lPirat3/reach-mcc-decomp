struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x2a8];
    bool field_2a8;
};
extern "C" bool function_3509e8(object_a* object, long long, object_c* input) {
    object->field_2a8 = input->field_8;
    return true;
}
