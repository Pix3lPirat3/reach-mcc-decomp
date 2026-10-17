struct object_a_field_18 {
    bool field_0;
};

struct object_a {
    unsigned char reserved0[0x18];
    object_a_field_18* field_18;
};
extern "C" void function_2d0634(object_a* object, bool second) {
    object->field_18->field_0 = second;
}
