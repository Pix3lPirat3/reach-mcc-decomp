struct object_a_field_18 {
    bool field_0;
};

struct object_a {
    unsigned char reserved0[0x18];
    object_a_field_18* field_18;
};

struct object_b {
    bool field_0;
};
extern "C" object_b* function_2d08b8(object_a* object, object_b* source) {
    source->field_0 = object->field_18->field_0;
    return source;
}
