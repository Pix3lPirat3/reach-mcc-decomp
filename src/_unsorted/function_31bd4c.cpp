struct object_c {
    unsigned char reserved0[8];
    unsigned long long field_8;
};

struct object_a {
    unsigned char reserved0[0x98];
    unsigned long long field_98;
};
extern "C" bool function_31bd4c(object_a* object, long long, object_c* input) {
    object->field_98 = input->field_8;
    return true;
}
