struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x79];
    bool field_79;
};
extern "C" bool function_3821a4(object_a* object, long long, object_c* input) {
    object->field_79 = input->field_8;
    return true;
}
