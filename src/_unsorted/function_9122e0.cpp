struct object_a_field_18 {
    unsigned char reserved0[8];
    float field_8;
};

struct object_a {
    unsigned char reserved0[0x18];
    object_a_field_18* field_18;
};
extern "C" float function_9122e0(object_a* object) {
    return object->field_18->field_8;
}
