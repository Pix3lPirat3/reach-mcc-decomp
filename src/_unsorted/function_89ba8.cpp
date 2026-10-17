struct vec128 {
    unsigned long long low;
    unsigned long long high;
};

struct object_b {
    vec128 field_0;
};

struct object_a {
    unsigned char reserved0[0x10];
    vec128 field_10;
};
extern "C" bool function_89ba8(object_a* object, object_b* source) {
    object->field_10 = source->field_0;
    return true;
}
