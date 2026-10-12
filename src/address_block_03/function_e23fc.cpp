struct object_a {
    unsigned char reserved0[5];
    bool field_5;
};

struct object_b {
    bool field_0;
};
extern "C" object_b* function_e23fc(object_a* object, object_b* source) {
    source->field_0 = object->field_5;
    return source;
}
