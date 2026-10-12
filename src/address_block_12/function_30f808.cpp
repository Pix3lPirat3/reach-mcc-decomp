struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x74];
    unsigned int field_74;
};
extern "C" bool function_30f808(object_a* object, long long, object_c* input) {
    object->field_74 = input->field_8;
    return true;
}
