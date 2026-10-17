struct object_a_field_18 {
    bool field_0;
};

struct object_a {
    unsigned char reserved0[0x18];
    object_a_field_18* field_18;
};
extern "C" bool function_2d0708(object_a* object) {
    return object->field_18->field_0;
}
