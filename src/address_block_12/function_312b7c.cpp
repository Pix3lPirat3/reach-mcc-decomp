struct object_a {
    unsigned char reserved0[0x278];
    bool field_278;
};

struct object_b {
    bool field_0;
};
extern "C" object_b* function_312b7c(object_a* object, object_b* source) {
    source->field_0 = object->field_278;
    return source;
}
