struct object_a_field_18 {
    float field_0;
};

struct object_a {
    unsigned char reserved0[0x18];
    object_a_field_18* field_18;
};
extern "C" float function_2d07e0(object_a* object) {
    return object->field_18->field_0;
}
