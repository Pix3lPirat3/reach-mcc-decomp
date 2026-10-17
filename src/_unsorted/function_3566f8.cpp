struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x1234];
    unsigned int field_1234;
};
extern "C" bool function_3566f8(object_a* object, long long, object_c* input) {
    object->field_1234 = input->field_8;
    return true;
}
