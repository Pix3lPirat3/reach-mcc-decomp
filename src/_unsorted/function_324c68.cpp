struct vec128 {
    unsigned long long low;
    unsigned long long high;
};

struct object_c {
    unsigned char reserved0[8];
    vec128 field_8;
};

struct object_a {
    unsigned char reserved0[0x1e8];
    vec128 field_1e8;
};
extern "C" bool function_324c68(object_a* object, long long, object_c* input) {
    object->field_1e8 = input->field_8;
    return true;
}
