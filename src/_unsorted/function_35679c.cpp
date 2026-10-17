struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x1248];
    unsigned int field_1248;
};
extern "C" bool function_35679c(object_a* object, long long, object_c* input) {
    object->field_1248 = input->field_8;
    return true;
}
