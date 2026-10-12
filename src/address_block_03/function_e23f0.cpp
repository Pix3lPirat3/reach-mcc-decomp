struct object_a {
    unsigned char reserved0[4];
    bool field_4;
};

struct object_b {
    bool field_0;
};
extern "C" object_b* function_e23f0(object_a* object, object_b* source) {
    source->field_0 = object->field_4;
    return source;
}
