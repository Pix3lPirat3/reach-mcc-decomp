struct object_a {
    unsigned char reserved0[0x2c];
    bool field_2c;
};
extern "C" void function_6f1994(object_a* object) {
    object->field_2c = false;
}
