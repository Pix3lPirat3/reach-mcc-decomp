struct object_a {
    unsigned char reserved0[0x1f8dc];
    unsigned int field_1f8dc;
};
extern "C" void function_3e44d8(object_a* object) {
    object->field_1f8dc += 1;
}
