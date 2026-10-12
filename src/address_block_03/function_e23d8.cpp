struct object_a {
    unsigned char reserved0[2];
    bool field_2;
};

struct object_b {
    bool field_0;
};
extern "C" object_b* function_e23d8(object_a* object, object_b* source) {
    source->field_0 = object->field_2;
    return source;
}
