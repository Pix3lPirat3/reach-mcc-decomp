struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x158];
    unsigned int field_158;
};
extern "C" bool function_34ed4c(object_a* object, long long, object_c* input) {
    object->field_158 = input->field_8;
    return true;
}
