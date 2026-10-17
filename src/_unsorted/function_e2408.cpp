struct object_a {
    unsigned char reserved0[6];
    bool field_6;
};

struct object_b {
    bool field_0;
};
extern "C" object_b* function_e2408(object_a* object, object_b* source) {
    source->field_0 = object->field_6;
    return source;
}
