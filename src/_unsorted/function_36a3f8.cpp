struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x188];
    bool field_188;
};
extern "C" bool function_36a3f8(object_a* object, long long, object_c* input) {
    object->field_188 = input->field_8;
    return true;
}
