struct object_a {
    unsigned char field_0;
};

struct object_b {
    unsigned char field_0;
};
extern "C" object_b* function_e23c4(object_a* object, object_b* source) {
    source->field_0 = object->field_0;
    return source;
}
