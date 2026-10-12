struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0xb2];
    bool field_b2;
};
extern "C" bool function_329e0c(object_a* object, long long, object_c* input) {
    object->field_b2 = input->field_8;
    return true;
}
