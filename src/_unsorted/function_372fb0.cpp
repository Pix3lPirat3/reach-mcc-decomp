struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x8b];
    bool field_8b;
};
extern "C" bool function_372fb0(object_a* object, long long, object_c* input) {
    object->field_8b = input->field_8;
    return true;
}
