struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x210];
    unsigned int field_210;
};
extern "C" bool function_34f0bc(object_a* object, long long, object_c* input) {
    object->field_210 = input->field_8;
    return true;
}
