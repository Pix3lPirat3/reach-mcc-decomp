struct object_a {
    unsigned char reserved0[8];
    unsigned int field_8;
};
extern "C" void function_c71fc(object_a* object, unsigned int second) {
    object->field_8 = second;
}
