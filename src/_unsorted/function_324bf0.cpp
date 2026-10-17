struct vec128 {
    unsigned long long low;
    unsigned long long high;
};

struct object_c {
    unsigned char reserved0[8];
    vec128 field_8;
};

struct object_a {
    unsigned char reserved0[0x1b8];
    vec128 field_1b8;
};
extern "C" bool function_324bf0(object_a* object, long long, object_c* input) {
    object->field_1b8 = input->field_8;
    return true;
}
