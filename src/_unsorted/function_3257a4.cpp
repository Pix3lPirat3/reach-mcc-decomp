struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x11c];
    unsigned int field_11c;
};
extern "C" bool function_3257a4(object_a* object, long long, object_c* input) {
    object->field_11c = input->field_8;
    return true;
}
