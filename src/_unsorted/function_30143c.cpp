struct vec128 {
    unsigned long long low;
    unsigned long long high;
};

struct object_c {
    unsigned char reserved0[8];
    vec128 field_8;
};

struct object_a {
    unsigned char reserved0[0x80];
    vec128 field_80;
};
extern "C" bool function_30143c(object_a* object, long long, object_c* input) {
    object->field_80 = input->field_8;
    return true;
}
