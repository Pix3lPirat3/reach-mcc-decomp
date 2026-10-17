struct object_c {
    unsigned char reserved0[8];
    unsigned long long field_8;
};

struct object_a {
    unsigned char reserved0[0xa0];
    unsigned long long field_a0;
};
extern "C" bool function_329b84(object_a* object, long long, object_c* input) {
    object->field_a0 = input->field_8;
    return true;
}
