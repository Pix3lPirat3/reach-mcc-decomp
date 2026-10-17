struct object_a {
    unsigned char reserved0[0x88];
    bool field_88;
};

struct object_c {
    bool field_0;
};
extern "C" void function_3e5ee0(object_a* object, long long, object_c* input) {
    input->field_0 = object->field_88;
}
