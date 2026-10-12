struct object_a_field_0 {
    int field_0;
};

struct object_b_field_0 {
    int field_0;
};

struct object_a {
    object_a_field_0* field_0;
};

struct object_b {
    object_b_field_0* field_0;
};
extern "C" bool function_2e9780(object_a* object, object_b* source) {
    return object->field_0->field_0 > source->field_0->field_0;
}
