struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0xd4];
    unsigned int field_d4;
};
extern "C" bool function_364940(object_a* object, long long, object_c* input) {
    object->field_d4 = input->field_8;
    return true;
}
