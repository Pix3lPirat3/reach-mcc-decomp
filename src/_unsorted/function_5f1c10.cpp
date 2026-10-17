struct object_a {
    unsigned char reserved0[0x1e0];
    unsigned long long field_1e0;
};

struct object_b {
    unsigned long long field_0;
};
extern "C" unsigned int function_5f1c10(object_a* object, object_b* source) {
    source->field_0 = object->field_1e0;
    return 0;
}
