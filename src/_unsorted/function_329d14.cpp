struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0xab];
    bool field_ab;
};
extern "C" bool function_329d14(object_a* object, long long, object_c* input) {
    object->field_ab = input->field_8;
    return true;
}
