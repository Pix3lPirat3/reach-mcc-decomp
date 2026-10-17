struct object_a {
    unsigned char reserved0[0x50];
    bool field_50;
};
extern "C" void function_6f1868(object_a* object) {
    object->field_50 = false;
}
