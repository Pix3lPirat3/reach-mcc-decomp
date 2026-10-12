struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x52c];
    unsigned int field_52c;
};
extern "C" bool function_3547f0(object_a* object, long long, object_c* input) {
    object->field_52c = input->field_8;
    return true;
}
