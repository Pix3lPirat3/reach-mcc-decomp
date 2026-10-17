struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x524];
    unsigned int field_524;
};
extern "C" bool function_3547a8(object_a* object, long long, object_c* input) {
    object->field_524 = input->field_8;
    return true;
}
