struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x154];
    unsigned int field_154;
};
extern "C" bool function_2fdd5c(object_a* object, long long, object_c* input) {
    object->field_154 = input->field_8;
    return true;
}
