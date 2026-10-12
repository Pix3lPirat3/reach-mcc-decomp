struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x160];
    unsigned int field_160;
};
extern "C" bool function_335fd0(object_a* object, long long, object_c* input) {
    object->field_160 = input->field_8;
    return true;
}
