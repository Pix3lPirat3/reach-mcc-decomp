struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x170];
    bool field_170;
};
extern "C" bool function_317a40(object_a* object, long long, object_c* input) {
    object->field_170 = input->field_8;
    return true;
}
