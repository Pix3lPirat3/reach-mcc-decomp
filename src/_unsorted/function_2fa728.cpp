struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x134];
    unsigned int field_134;
};
extern "C" bool function_2fa728(object_a* object, long long, object_c* input) {
    object->field_134 = input->field_8;
    return true;
}
