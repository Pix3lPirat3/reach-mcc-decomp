struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x164];
    unsigned int field_164;
};
extern "C" bool function_2d2efc(object_a* object, long long, object_c* input) {
    object->field_164 = input->field_8;
    return true;
}
