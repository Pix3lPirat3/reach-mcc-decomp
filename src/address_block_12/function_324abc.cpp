struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x204];
    unsigned int field_204;
};
extern "C" bool function_324abc(object_a* object, long long, object_c* input) {
    object->field_204 = input->field_8;
    return true;
}
