struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x2a9];
    bool field_2a9;
};
extern "C" bool function_350a0c(object_a* object, long long, object_c* input) {
    object->field_2a9 = input->field_8;
    return true;
}
