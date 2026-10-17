struct object_b {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned long long field_0;
};
extern "C" unsigned long long function_7e4490(object_a* object, object_b* source) {
    return source->field_8 + object->field_0;
}
