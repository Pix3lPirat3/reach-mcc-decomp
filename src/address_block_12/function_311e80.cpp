struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x108];
    unsigned int field_108;
};
extern "C" bool function_311e80(object_a* object, long long, object_c* input) {
    object->field_108 = input->field_8;
    return true;
}
