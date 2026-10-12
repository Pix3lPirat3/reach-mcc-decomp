struct object_c {
    unsigned char reserved0[8];
    bool field_8;
};

struct object_a {
    unsigned char reserved0[0x2aa];
    bool field_2aa;
};
extern "C" bool function_350a30(object_a* object, long long, object_c* input) {
    object->field_2aa = input->field_8;
    return true;
}
