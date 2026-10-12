struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x8c4];
    unsigned int field_8c4;
};
extern "C" bool function_350b88(object_a* object, long long, object_c* input) {
    object->field_8c4 = input->field_8;
    return true;
}
