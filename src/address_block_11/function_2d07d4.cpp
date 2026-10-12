struct object_a_field_18 {
    float field_0;
};

struct object_a {
    unsigned char reserved0[0x18];
    object_a_field_18* field_18;
};
extern "C" void function_2d07d4(object_a* object, float second) {
    object->field_18->field_0 = second;
}
