struct object_a {
    unsigned char reserved0[1];
    bool field_1;
};

struct object_b {
    bool field_0;
};
extern "C" object_b* function_e23cc(object_a* object, object_b* source) {
    source->field_0 = object->field_1;
    return source;
}
