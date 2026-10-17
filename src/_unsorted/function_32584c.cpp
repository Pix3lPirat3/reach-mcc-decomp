struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x12c];
    unsigned int field_12c;
};
extern "C" bool function_32584c(object_a* object, long long, object_c* input) {
    object->field_12c = input->field_8;
    return true;
}
