struct object_a {
    unsigned char reserved0[0x20];
    unsigned int field_20;
};

struct object_b {
    unsigned int field_0;
};
extern "C" unsigned int function_5833b0(object_a* object, object_b* source) {
    source->field_0 = object->field_20;
    return 0;
}
