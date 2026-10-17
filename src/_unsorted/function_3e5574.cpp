struct object_a {
    unsigned char reserved0[0x88];
    unsigned long long field_88;
};

struct object_c {
    unsigned long long field_0;
};
extern "C" void function_3e5574(object_a* object, long long, object_c* input) {
    input->field_0 = object->field_88;
}
