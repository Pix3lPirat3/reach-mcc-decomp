struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x8d0];
    unsigned int field_8d0;
};
extern "C" bool function_350bc4(object_a* object, long long, object_c* input) {
    object->field_8d0 = input->field_8;
    return true;
}
