struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0xb4];
    unsigned int field_b4;
};
extern "C" bool function_30ce9c(object_a* object, long long, object_c* input) {
    object->field_b4 = input->field_8;
    return true;
}
