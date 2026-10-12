struct object_a {
    unsigned char reserved0[0x33c10];
    bool field_33c10;
};
extern "C" void function_8dc94(object_a* object) {
    object->field_33c10 = true;
}
