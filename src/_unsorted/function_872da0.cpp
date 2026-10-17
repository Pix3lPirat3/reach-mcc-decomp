struct object_a {
    unsigned char reserved0[0x10];
    unsigned long long field_10;
};

struct object_b {
    bool field_0;
};
extern "C" object_b* function_872da0(object_a* object, object_b* source) {
    source->field_0 = object->field_10 != 0ull;
    return source;
}
