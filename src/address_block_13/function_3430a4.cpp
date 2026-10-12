struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x2ac];
    unsigned int field_2ac;
};
extern "C" bool function_3430a4(object_a* object, long long, object_c* input) {
    object->field_2ac = input->field_8;
    return true;
}
