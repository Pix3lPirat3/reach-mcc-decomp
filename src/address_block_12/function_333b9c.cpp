struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x9a0];
    unsigned int field_9a0;
};
extern "C" bool function_333b9c(object_a* object, long long, object_c* input) {
    object->field_9a0 = input->field_8;
    return true;
}
