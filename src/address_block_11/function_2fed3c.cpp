struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x98];
    unsigned int field_98;
};
extern "C" bool function_2fed3c(object_a* object, long long, object_c* input) {
    object->field_98 = input->field_8;
    return true;
}
