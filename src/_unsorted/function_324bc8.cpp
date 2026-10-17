struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x1f8];
    bool field_1f8;
};
extern "C" bool function_324bc8(object_a* object, long long, object_c* input) {
    object->field_1f8 = input->field_8;
    return true;
}
