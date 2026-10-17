struct object_a {
    unsigned int field_0;
};

struct object_b {
    unsigned int field_0;
};
extern "C" unsigned int function_10cac0(object_a* object, object_b* source) {
    return object->field_0 - source->field_0;
}
