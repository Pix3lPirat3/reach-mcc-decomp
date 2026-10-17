struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0xb0];
    bool field_b0;
};
extern "C" bool function_30ce78(object_a* object, long long, object_c* input) {
    object->field_b0 = input->field_8;
    return true;
}
