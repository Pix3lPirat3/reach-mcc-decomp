struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x80];
    unsigned int field_80;
};
extern "C" bool function_300da8(object_a* object, long long, object_c* input) {
    object->field_80 = input->field_8;
    return true;
}
