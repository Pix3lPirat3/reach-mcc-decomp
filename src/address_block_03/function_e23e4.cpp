struct object_a {
    unsigned char reserved0[3];
    bool field_3;
};

struct object_b {
    bool field_0;
};
extern "C" object_b* function_e23e4(object_a* object, object_b* source) {
    source->field_0 = object->field_3;
    return source;
}
