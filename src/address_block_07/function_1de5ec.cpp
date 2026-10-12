struct object_a {
    unsigned char reserved0[0x2c];
    bool field_2c;
};
extern "C" void function_1de5ec(object_a* object, bool second) {
    object->field_2c = second;
}
