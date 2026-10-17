struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0xaf];
    bool field_af;
};
extern "C" bool function_329d7c(object_a* object, long long, object_c* input) {
    object->field_af = input->field_8;
    return true;
}
