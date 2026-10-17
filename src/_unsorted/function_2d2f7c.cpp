struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x1bc];
    unsigned int field_1bc;
};
extern "C" bool function_2d2f7c(object_a* object, long long, object_c* input) {
    object->field_1bc = input->field_8;
    return true;
}
