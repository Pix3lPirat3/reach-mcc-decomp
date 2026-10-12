struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x141];
    bool field_141;
};
extern "C" bool function_36a2f8(object_a* object, long long, object_c* input) {
    object->field_141 = input->field_8;
    return true;
}
