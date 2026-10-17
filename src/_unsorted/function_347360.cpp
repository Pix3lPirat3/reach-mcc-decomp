struct object_a {
    unsigned char reserved0[0x84];
    unsigned int field_84;
};
extern "C" unsigned int function_347360(object_a* object) {
    return object->field_84;
}
