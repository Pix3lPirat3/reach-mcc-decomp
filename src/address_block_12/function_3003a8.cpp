struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x174];
    unsigned int field_174;
};
extern "C" bool function_3003a8(object_a* object, long long, object_c* input) {
    object->field_174 = input->field_8;
    return true;
}
