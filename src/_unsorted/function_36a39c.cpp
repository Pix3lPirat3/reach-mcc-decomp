struct vec128 {
    unsigned long long low;
    unsigned long long high;
};

struct object_c {
    unsigned char reserved0[8];
    vec128 field_8;
};

struct object_a {
    unsigned char reserved0[0x178];
    vec128 field_178;
};
extern "C" bool function_36a39c(object_a* object, long long, object_c* input) {
    object->field_178 = input->field_8;
    return true;
}
