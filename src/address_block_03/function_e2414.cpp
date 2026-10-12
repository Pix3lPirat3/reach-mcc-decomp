struct object_a {
    unsigned char reserved0[7];
    bool field_7;
};

struct object_b {
    bool field_0;
};
extern "C" object_b* function_e2414(object_a* object, object_b* source) {
    source->field_0 = object->field_7;
    return source;
}
