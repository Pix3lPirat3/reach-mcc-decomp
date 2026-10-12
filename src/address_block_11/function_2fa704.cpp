struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x130];
    unsigned int field_130;
};
extern "C" bool function_2fa704(object_a* object, long long, object_c* input) {
    object->field_130 = input->field_8;
    return true;
}
