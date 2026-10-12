struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x148];
    unsigned int field_148;
};
extern "C" bool function_3062dc(object_a* object, long long, object_c* input) {
    object->field_148 = input->field_8;
    return true;
}
