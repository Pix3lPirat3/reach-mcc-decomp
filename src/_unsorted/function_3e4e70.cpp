struct object_a {
    unsigned char reserved0[0x1b45c];
    unsigned int field_1b45c;
};
extern "C" void function_3e4e70(object_a* object) {
    object->field_1b45c += 1;
}
