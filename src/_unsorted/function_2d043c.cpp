struct object_a_field_18 {
    unsigned int field_0;
};

struct object_a {
    unsigned char reserved0[0x18];
    object_a_field_18* field_18;
};
extern "C" void function_2d043c(object_a* object, unsigned int second) {
    object->field_18->field_0 = second;
}
