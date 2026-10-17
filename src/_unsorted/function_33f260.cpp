struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x71];
    bool field_71;
};
extern "C" bool function_33f260(object_a* object, long long, object_c* input) {
    object->field_71 = input->field_8;
    return true;
}
