struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x208];
    unsigned int field_208;
};
extern "C" bool function_324ae0(object_a* object, long long, object_c* input) {
    object->field_208 = input->field_8;
    return true;
}
