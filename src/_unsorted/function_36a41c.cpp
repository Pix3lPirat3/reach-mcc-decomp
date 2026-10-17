struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x189];
    bool field_189;
};
extern "C" bool function_36a41c(object_a* object, long long, object_c* input) {
    object->field_189 = input->field_8;
    return true;
}
