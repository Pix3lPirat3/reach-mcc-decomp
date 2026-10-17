struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x200];
    unsigned int field_200;
};
extern "C" bool function_324a98(object_a* object, long long, object_c* input) {
    object->field_200 = input->field_8;
    return true;
}
