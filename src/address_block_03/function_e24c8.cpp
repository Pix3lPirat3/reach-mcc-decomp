struct object_a {
    unsigned char reserved0[0x7e8];
    unsigned int field_7e8;
};

struct object_b {
    unsigned long long field_0;
};
extern "C" object_b* function_e24c8(object_a* object, object_b* source) {
    source->field_0 = object->field_7e8;
    return source;
}
