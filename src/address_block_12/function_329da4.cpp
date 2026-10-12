struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0xae];
    bool field_ae;
};
extern "C" bool function_329da4(object_a* object, long long, object_c* input) {
    object->field_ae = input->field_8;
    return true;
}
