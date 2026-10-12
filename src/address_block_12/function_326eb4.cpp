struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0xcc];
    unsigned int field_cc;
};
extern "C" bool function_326eb4(object_a* object, long long, object_c* input) {
    object->field_cc = input->field_8;
    return true;
}
