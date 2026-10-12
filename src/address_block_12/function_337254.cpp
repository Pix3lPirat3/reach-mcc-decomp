struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x88];
    unsigned int field_88;
};
extern "C" bool function_337254(object_a* object, long long, object_c* input) {
    object->field_88 = input->field_8;
    return true;
}
