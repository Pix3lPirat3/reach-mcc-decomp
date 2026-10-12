struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x128];
    unsigned int field_128;
};
extern "C" bool function_325828(object_a* object, long long, object_c* input) {
    object->field_128 = input->field_8;
    return true;
}
