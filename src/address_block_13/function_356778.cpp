struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x1244];
    unsigned int field_1244;
};
extern "C" bool function_356778(object_a* object, long long, object_c* input) {
    object->field_1244 = input->field_8;
    return true;
}
